#############################
Pinnacle Design Specification
#############################
Product Name:

Feature Name:

Product Version:

========================================
TEMPLATE REVISION HISTORY & INSTRUCTIONS
========================================

Template Revision History
=========================

This template is for defining feature specifications and design. Customize it for your product.

========    ==================================  ==========
Template    Version/Date Description of Change  Originator
========    ==================================  ==========

Template Instructions
=====================

- Content instructions to prepare this document are provided in <brackets> within each section of this template.
- Insert document content after the instructions.
- Include diagrams, tables, and charts when possible, they can make the document more readable for others. 
- Not all features will need each section in this document.  
- Feel free to delete sections that aren’t relevant.  
- If the only content for a section is "Not applicable", take out the whole section. 
- The section headings are intended as a checklist, so do some research before deciding that something isn't applicable.
- To help the writer the sections are marked as MUST-HAVE or OPTIONAL to indicate their importance. 
- Some features will need extra sections.  Feel free to add what you need.
- Delete the "Template Revision History”, “Template Instructions" and “Document purpose and Use” sections, and also the sections instructions after completing the document sections. They should exist only in the template and not in the finished document.
- Update the table of contents after editing.  (This is done by clicking to the left of the old table of contents and then pressing F9).

Document Purpose and Use
========================
- The document is going to be used to clarify the requirements, and define the high level, externally visible behavior and implementation of your feature. It will also describe the testing for your feature.
- The Requirements section will confirm that Engineering’s understanding of the requirements matches Product Management’s understanding of the requirements.  
- Different parts of this document can be used as input for Tech Pubs, Usability Lab and QA. 
- Refer to the instructions with each section for more guidance.
- In the final document there should be an obvious mapping: from the requirements to the high level design and from the high level design to the implementation of the feature.
- Give a detailed overview of external and internal interfaces, data structures, algorithms, protocols, state machines, etc. as described in the template’s instructions for each section.
- Major sections may be completed and reviewed in phases.  This will often be preferable to writing the entire document all at once.


DOCUMENT REVISION HISTORY & APPROVALS

Document Revision History
=========================

Document
Revision/Date
Description of Change
Originator

yyyy/mm/dd

Document Approvals:
===================

Project Team Role/Function
Approval
Date
Project Manager or Lead Engineer
Name:  __________________________________________
Signature:  [ filled-in date implies signature ]

Product Manager
Name:  __________________________________________
Signature:  [ filled-in date implies signature ]

Review Record:
==============

Reviewer
Sections Reviewed 
Date

============
INTRODUCTION
============

<Give a general overview of the background and context for this proposal.  This can include related academic work, requirements of other features or products, features in products offered by related products, or any other background information that would be helpful to the reader. MUST-HAVE section. >

FUNCTIONAL OVERVIEW
===================

< Give a high level overview of the functionality of the feature and possibly general architecture, but independent of design/implementation.  Diagrams(s) can be very useful here. >

============
REQUIREMENTS
============

< Use this section to define the requirements that your feature is expected to fulfill. Specific requirements are to be included in the subsections 2.1 – 2.7. Within each subsection, any requirements which were derived from the MRD should be so noted. This first part of section 2 is OPTIONAL, but 2.1 – 2.7 are MUST-HAVE. >


  ** More bonus points if you can implement persistent hash table.

FUNCTIONAL REQUIREMENTS
=======================

< Describe what this feature is required to accomplish for the consumer. >

*   Provide an interface for storing key-value pairs replicated accross two nodes.
*   The nodes will be in Active-passive mode.
*   Backed Up entries in a secondary node.
*   Supports standard APIs like insert/search/delete/update.
*   The data could be string/binary.
*   In the context of insert/update/delete, make an entry into the intent log (aka WAL - write ahead log).
*   When secondary node acknowledges the received WAL entries, primary cleans up the corresponding WAL entries (i.e. upto the ACKed sequence number).
*   WAL can be kept in memory.
*   If the secondary crashes and comes back up, it resyncs with primary.   No need to handle failure of primary. 
*   In  a steady state, the secondary should be in a condition to be used for searches (it could be inconsistent though - compared to primary)
*   The replication to the secondary must be done via a background thread. 

USABILITY REQUIREMENTS
======================

< Describe how the user or consumer is required interact with this feature.>

*   Provide interface for the user to insert/update/delete/search entries in the hash table.
*   Data can be string or binary. Keys will always be string.

ADMINISTRATIVE REQUIREMENTS
===========================

< Describe how this feature is required to be managed and controlled by the system administrator.>

PERFORMANCE REQUIREMENTS
========================

< List the performance requirements, if any, placed on this feature. >

*   Hash table must be able to do the searches in O(1) time.

REQUIRED INTERACTIONS WITH OTHER PRODUCT FEATURES AND OTHER PRODUCTS
====================================================================

< Define any required interactions with other features of the same product and with other products.>

TESTABILITY REQUIREMENTS
========================

< Define any required aids for testing this feature.>

NON REQUIREMENTS
================

< This subsection is available to reduce ambiguity.  List any items that this feature is not expected to do, that the reader might otherwise think is expected. >

*   Hash table is not required to save the entries on the disk.
*   WAL entries are not required to be saved on the disk.
*   No provision for adding more than 2 nodes to the system.
*   Writing new message passing is not required. Use any existing framework like Apache Thrift.

=================
HIGH LEVEL DESIGN
=================

< Use this section to describe what your feature will do and give an overview of your design.  Include a summary of how your design fits into the overall architecture of the product. Also include a high level view of the important external interfaces for your feature. The first 2 subsections below are MUST-HAVE. Subsections are given as a reminder of what kind of info needs to be included. One or more diagrams are expected to be found in this section. >

ADMINISTRATOR’S VIEW
====================

< New administrative commands, changes to existing commands, policy settings, configuration files, default behavior, or anything else of interest to the system administrator.  >

*   phash start
    
    -   this will start the phash service on the primary node and the secondary node. User must give the IP/username and the password of the secondary node in the command line.
    -   the node on which this command is called will be the primary node and the other node will be the secondary node.
    
.. graphviz::
   
	digraph G {                                                                


	user -> cd1 [label="Ops"]                                   

	subgraph cluster_0 {                                                
	style=filled;                                                   
	color=lightgrey;                                                
	node [style=filled,color=white];                                

	cp1 [label="class Phash"] 
	cw1 [label="class WAL"]

	cw1 -> cp1 [label="Ops"]
	cm1 [label="class std::map"]
	cp1 -> cm1
	cd1 [label="class PhashDriver"   ]
	cd1 -> cw1 [label="Ops"]                                        
	}  
	thirft [label="thirft"] 
	cw1 -> thirft -> cw2  [label="data" style="dashed" arrowhead="normal" arrowtail="normal" dir="both"]                                                                     

	subgraph cluster_1 {                                                
	node [style=filled];                                            

	label = "Secondary Node";                                     
	color=blue 
	cw2 [label="class WAL"] 
	cp2 [label="class Phash"]                                                   
	cw2 -> cp2 [label="Ops"] 
	}                                                                   
	cw1 -> cw2 [label="Heartbeat" style="dashed" arrowhead="normal" arrowtail="normal" dir="both"]                                                              

        }                             

class Ops
---------

*	Creates an Ops structure. This structure has enough information which can be used by another WAL class to do its work.

*	Ops class will have the following fields. Operation Type, Key, Value.

*	Primary WAL will create an Ops structure and will send it to the secondary WAL. Secondary WAL will open the Ops and will run the Operation on the Phash class.


class WAL
---------

*	On any operation will create a Ops class's object and sends to the local Phash class.
*	The Ops object will be put in the Primary WALs OpsTable and then send to the secondary WAL.
*	Every Ops structure will have a UDID associated with it which can uniquely identify the Ops in both the WALs, primary and secondary.
*	When the secondary completes the operation requested in the Ops, it will send an ACK with the errno and errmsg to the primary WAL.
*	Primary WAL will delete the Ops entry from the Ops Table.

Protected Interface
+++++++++++++++++++

*	submit_ops (class ops obj)

	-	Submits the Ops to the Phash class on the local node.	


class WALServer
---------------

*	Start the WAL in the server mode. Must be run on the primary node.
*	Starts another thread to send the OpsObject to the secondary node.

Public Interface
+++++++++++++++++

*	submit_ops()

	-	This function recieves the Ops object and sends it to the WALClient on secondary. Maitains a OpsTable for marking the Ops which has been processed by the Client.


class WALClient
---------------

*	Starts the WAL in the client mode. Must be run on the secondary node.

*	submit_ops()
	
	-	When running in the client mode the function sends the Ops to the local Phash and based on the return value sends the ACK for the given OpsObject.

class PhashDriver
-----------------

*	Connects to the WALServer and submits Ops to it.

Public Interface
++++++++++++++++

*	PhashDriver(hostname1, hostname2)
	
	-	Talks to the local WAL service running on a port and does initial checks.
	-	Depending on the WAL type (primary/secondary) sets the allowed operations. If it is secondary node only searches should be allowed.

-	insert(K, V)
	
	-	Insert the K,V pair to the WAL layer.

-	search(K)

	-	Search for a K

-	delete(K)
	
	-	delete the K

-	update(K, V)
	
	-	update the K,V

class Phash
-----------

EXTERNAL API’s CLI, GUI
=======================

< Other external interfaces not covered by above. >

EXTERNAL PROTOCOLS
==================

< Provide info about any external protocols used by this feature. >

NOTIFICATION EVENTS 
====================

< Notification events, if any, raised by the feature. >

OTHER HIGH LEVEL INFO
=====================

< List any restrictions on where or how this feature will be used (for example only for certain kinds of clients).  
Alternate design options may be mentioned, but only briefly and at the high level. If these alternate options need to be described better this can be done in an Appendix. >

===============
DETAILED DESIGN
===============

< Use this section to describe the details of your design and how they are expected to map to the actual implementation.  If your proposal modifies an existing feature or component, describe the proposed changes. 

All the interfaces from “High level design” are expected to be covered in this section but this time in lower-level detail. Also, here we want to include both internal and external interfaces and protocols, and cover details such as error recovery and logging, and optionally packaging and installation.
Use of some diagrams is expected in this section. 
In some cases (some of) the following subsections may be merged. This section is MUST-HAVE. >

FEATURE’S SUB-COMPONENTS
========================

< List all the sub-components of your feature (for example, a kernel module and a user-level daemon) and say what they do.  Also list all the existing product modules that will be affected by your feature (for example, new flags in the administrative CLI) and the remote clients’ components that are expected to interact with your feature. The interfaces between your feature and these other modules will be described in detail below.>

FEATURE’S EXTERNAL INTERACTIONS
===============================

< Describe in detail how your feature will interact with other SFS and external to SFS components, including all the externally visible interfaces and protocols.  Expand this into multiple subsections if necessary.  Use the Interoperability Checklist, below as a guide for the topics to be covered here. >

FEATURE’S INTERNAL INTERACTIONS
===============================

< Define any internal APIs or communication protocols that you will use between the new feature’s components.  Note that this subsection is only for interfaces that are not visible to the external components.>

MAIN DATA STRUCTURES
====================

< Describe the (new or changed) main data structures used by the feature. >

ALGORITHMS
==========

< Describe the algorithms that you will be using. Use pseudo-code if possible. Describe the type of locking that feature will be using, locking hierarchy, any locking performance implications, and list the objects that you will need to lock.>

STATE MACHINES
==============

< Show the all the states that your feature will pass through, and show how each will be handled. >

PLATFORM COMPATIIBILITY, SECURITY, AND SUPPORTABILITY/DEBUGGING
===============================================================

< Describe any OS dependencies (version and patch level) as well as any dependencies on a specific version of some kernel-level or some user-level component. 
Describe the secure coding practices that you plan to use when developing this feature.
Describe any debugging aids that will be included with your feature (for example, log records and log levels or display commands). >

===========
PERFORMANCE
===========

< Describe any performance risks for your design, and explain how you plan to mitigate them. If possible give the metrics that will be used to measure the feature and list the workloads that are considered important for the feature and the tools that can be used to measure its performance. This section is MUST-HAVE.>

===============================
CONFIGURATION EXPORT AND IMPORT
===============================

<Describe the configuration export and import related stuff here. Please explain, if export and import options are not needed for this feature. This section is MUST-HAVE>

==========================
INTEROPERABILITY CHECKLIST
==========================

< For each item on the checklist, indicate whether your feature will or will not interoperate with that component, by stating “Coexist”, “Interact”, or “Incompatible”.  All “Interact” and “Incompatible” items must be described in the “Interactions with other components” subsection above. The list of components below is given as an example; it can be changed if necessary. This section is MUST-HAVE.>

Functionality/Component Interoperability

================
CONTINGENCY PLAN
================

< Describe how this feature can be backed off in the event that it needs to be dropped from SFS or what needs to be done so that code is disabled at compile time and at runtime.  Options include turning off a feature bit, removing self-contained modules from the package lists, editing makefiles, or other techniques as appropriate. This section is OPTIONAL.>

====================
FUTURE POSSIBILITIES
====================

< Describe any thoughts you have on how the feature can be enhanced in the future. This section is OPTIONAL.>

====================
DOCUMENTATION IMPACT
====================

< For each subsection below, give the numbers in that document that will need changes.  If your feature does not impact the document, enter "No impact." If possible indicate what kind of changes will be required. It is not necessary to include a full new chapter or section or a full new man page here. This section is MUST-HAVE.>

ADMINISTRATOR’S GUIDE
=====================

< Please follow the instructions in 9.0 >

INSTALLATION GUIDE
==================

< Please follow the instructions in 9.0. >

MAN PAGES
=========

< Please follow the instructions in 9.0. >

RELEASE NOTES
=============

< Please follow the instructions in 9.0. >

=======
TESTING
=======

< This introductory part of the section can be used to: 1. briefly describe what kind of unit testing is going to be done and 2. give the general features of the test suite to be used by QA, or recommend such a test suite (some specifics about the test suite can be found in the subsections).  Most of this section is MUST-HAVE. Some subsections, for example stress or performance, may be optional for your feature.>

HARDWARE SETUP
==============

< Describe the hardware requirements for your tests.>

SOFTWARE SETUP
==============

< Describe in detail the required software environment for your tests. >

USABILITY TESTS
===============

< Describe any testing that should be done by the Usability Lab for this feature.  >

FUNCTIONAL CONFORMANCE TESTS
============================

< Describe the test cases that will verify conformance with the functional specification for this feature. >

API CONFORMANCE TESTS
=====================

< Describe the tests that will verify conformance with new APIs introduced with this feature.  “API” includes CLI’s used in shell scripts, exposed log record formats, protocols, and any other form of programmable interface. >

CODE COVERAGE TESTS
===================

< Describe the tests that will exercise the code paths (if not already covered by the previous subsections). >

ERROR INJECTION AND FAILURE SIMULATION TESTS
============================================

< Describe the tests that will exercise error recovery code and failure recovery code. >

STRESS TESTS
============

< Describe the tests that will exercise operational limits. >

PERFORMANCE TESTS
=================

< Describe the tests that will measure performance.>

===================
LEGAL REQUIREMENTS:
===================
Declaring Third-Party Sources, List of Patent Applications and Infringement Risks

< List any third-party components that will be incorporated into this feature.  Include both open source and commercially licensed components. List any patent applications that have been filed for this feature. List any patents the feature may infringe upon.  Use this section to list any known patents that may pose a risk. Legal will then conduct any required investigations. The section is MUST-HAVE.>


==================================
GLOSSARY OF NEW AND EXISTING TERMS
==================================

< Use this section to define acronyms and any obscure terms.  This section is for both the new terms introduced in this document as well as for the existing terms that an uninitiated reader might not know. Definitions must be given for such terms, this information can be used in the documentation. The section is MUST-HAVE if there any such terms, otherwise OPTIONAL.>

==========
REFERENCES
==========

< List any documents or web pages that will help illuminate your design. This section is OPTIONAL.>

========
APPENDIX
========

< Add any other stuff you need, for example more information about some alternate design options.  The section is OPTIONAL. >

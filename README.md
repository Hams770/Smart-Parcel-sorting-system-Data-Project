# Smart-Parcel-sorting-system-Data-Project
## Overview
The Smart Parcel Sorting System efficiently organizes parcels based on delivery routes and priority, leveraging data structures like queues, stacks, linked lists, arrays, and tree-based classification. This system enhances logistics by automating parcel sorting, reversing batches, and structuring delivery zones.

## Key Features
- Parcel Queue Management: Uses a FIFO (First-In-First-Out) strategy for incoming parcels.
- Stack-Based Batch Reversal: The stack follows a LIFO (Last-In, First-Out) approach, ensuring the last added parcel is processed first , Implements a stack structure for priority-based reordering.
- Sorting with Arrays & Linked Lists: Stores parcels dynamically while maintaining order based on priority.
- Hierarchical Classification: Organizes parcels using a tree-based structure, mapping region-city-zone relationships.

## Setup Instructions

### System Requirements
To run the Smart Parcel Sorting System, ensure:
- C++ Compiler.
- Standard Libraries: `iostream`, `string`, and memory management.

## Project Structure

SmartParcelSortingSystem/
│── src/
│ ├── Queu.cpp # Manages parcel queue operations
│ ├── Stack.cpp # Implements stack-based batch reversal
│ ├── Storage.cpp # Handles sorting with arrays & linked lists
│ ├── HierarchyTree.cpp # Classifies parcels using a tree-based structure
│── main.cpp # Main entry point
│── README.md # Project documentation

## Usage Instructions
### 1. Queue Management
- Enqueue parcels into the queue based on their arrival.
- Dequeue parcels for processing in sequential order.

### 2. Stack-Based Batch Reversal
- Push parcels into a stack structure.
- Reverse priority-based batches efficiently.

### 3. Sorting with Arrays & Linked Lists
- Parcels are stored dynamically while maintaining order based on priority.
- Linked list approach enables efficient insertion & retrieval.

### 4. Hierarchical Classification
- Parcels are grouped into regions, cities, and zones using a tree-based classification system.

## Contributions

• Hams Aljohani: Designed and implemented the Stack system for reversing parcel batches . Also designed and implemented the Tree-Based Hierarchy for Region-City-Zone Classification.

• Linah Aljiffri: Implemented Array and Linked List modules.

• Juri Bajaba: Designed and implemented the Queue system.

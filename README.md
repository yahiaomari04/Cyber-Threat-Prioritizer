Cyber Threat Prioritizer

A C++ command-line application that evaluates and prioritizes cybersecurity alerts based on their severity levels and CVSS scores.

The project implements a risk scoring mechanism combined with the Heap Sort algorithm to rank security alerts from highest to lowest priority.

Project Overview

Security teams often receive multiple alerts that require investigation. Prioritizing these alerts helps analysts identify which threats require immediate attention.

This project demonstrates a basic approach to threat prioritization by calculating a risk score for each alert and sorting alerts according to their calculated risk.

Features

* Alert Management: Enter multiple security alerts.
* Severity Classification: Supports Low, Medium, High, and Critical levels.
* CVSS Input: Accepts CVSS scores between 0.0 and 10.0.
* Risk Score Calculation: Calculates a risk score using severity weight and CVSS score.
* Heap Sort Algorithm: Sorts alerts from highest to lowest risk score.
* Input Validation: Handles invalid inputs and unsupported severity levels.
* Priority Ranking: Displays ranked alerts and identifies the highest-priority alert.

Risk Scoring Methodology

The application calculates the risk score using the following formula:

Risk Score = CVSS Score × Severity Weight

Severity	Weight
Low	1
Medium	2
High	3
Critical	4

Example:

An alert with:

* Severity: Critical
* CVSS Score: 8.5
* Severity Weight: 4

Will receive:

Risk Score = 8.5 × 4 = 34.0

Technologies & Concepts

* C++
* Data Structures
* Heap Data Structure
* Heap Sort Algorithm
* Risk Scoring
* CVSS
* Input Validation

Algorithm Complexity

Operation	Complexity
Heap Construction	O(n)
Heap Sort	O(n log n)
Additional Space	O(1) auxiliary space

How to Run

1. Clone the repository

git clone YOUR_REPOSITORY_URL

2. Navigate to the project directory

cd cyber-threat-prioritizer

3. Compile the source code

Using g++:

g++ -std=c++11 -Wall -Wextra main.cpp -o threat_prioritizer

4. Run the application

On Windows:

.\threat_prioritizer.exe

Example Output

========================================
       CYBER THREAT PRIORITIZER
========================================
========== PRIORITY ORDER ==========
Rank  Alert     Attack Type         Severity    CVSS    Risk
------------------------------------------------------------
1     102       Ransomware          Critical    8.5     34.0
2     101       SQL Injection       High        9.0     27.0
3     103       Phishing            Medium      6.0     12.0
========== HIGHEST PRIORITY ==========
Alert ID: 102
Attack Type: Ransomware
Severity: Critical
CVSS Score: 8.5
Risk Score: 34.0

Note: Example output is illustrative.

Project Purpose

This project was developed as a practical application of C++ programming, data structures, and algorithmic problem-solving in a cybersecurity context.

Limitations

* Uses manually entered alert data.
* Does not retrieve live threat intelligence.
* Does not integrate with SIEM platforms.
* Uses a simplified risk scoring model rather than a formal enterprise risk assessment methodology.

Disclaimer

This project is intended for educational purposes and demonstrates a simplified approach to cybersecurity alert prioritization.

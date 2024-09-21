![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md) [![Part.2](https://img.shields.io/badge/Part.2-Implementation-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)

# MCU development from scratch

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [History](#history)
- [Concept](#Concept)
- [Trainer](#Trainer)
- [Preparation](#Preparation)
- [Part.1[Basic]](#Part1_Basic)
- [Part.2[Implementation]](#Part2_Implementation)
- [Tip001: Show me the Badge](#Tip001)

</details>

<div id="history"></div>
<details open>
<summary><font size="5"><b>History</b></font></summary> 

- [TOC](#toc)<br>
- v0.1 2024/09/14 Seho.Seo Brand new document.
- v0.2 2024/09/15 Seho.Seo Remove Part3, it might be rescheduled.

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>Concept</b></font></summary>

- [TOC](#toc)<br>
- This program aims to provide a guide for those who are interested in MS development but are worried about ***where to start***.
- Regarding **MS development environment** ([Part.1[Basic]](Part1_Basic)) and **Requirements, product development** ([Part.2[Implementation]](#Part2_Implementation))
follow the steps in order and proceed.
- We're gonna practice a simple project at the [Part.2[Implementation]](#Part2_Implementation), with [Process and Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md) on the [Part.1[Basic]](#Part1_Basic).<br><br>
![gantt_chart_deliverables_by_division](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/gantt_chart_deliverables_by_division.png)
- Keep in mind [**Golden ratio**](https://en.m.wikipedia.org/wiki/Golden_ratio) and [**Affordance**](https://en.m.wikipedia.org/wiki/Affordance), divide and conquer with [**Occam's razor**](https://en.m.wikipedia.org/wiki/Occam%27s_razor). 

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>Trainer</b></font></summary>

- [TOC](#toc)<br>
- Seho Seo, Korean, 50s
- Graduated from Pusan University, Department of Computer Science.
- Working as a MS engineer for 21 years in Japan, home appliance (cellular phone, digital camera), FA sensor (color mark, water flow, pressure, length measurement, etc), and automotive fields.
- Hobbies are fishing, speakers, Costco...

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>Preparation</b></font></summary>

- [TOC](#toc)<br>
- In this program, we're gonna practice with evaluation board.
- Which supplier shall we use?<br>
There is almost no difference between five major suppliers (NXP, Microchip, Renesas, ST, Infineon), with  market share of **82**%, **ST** shall be a good fellow given its potential for growth.<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png)<br>
[Top 5 Manufacturers in the MCU Market](https://www.onerivertronics.com/a/43018.html)<br>
[Top 5 MCU Manufacturers View for the Development of the Microcontroller Market](https://www.hardfindelec.com/a/76030.html)
- Which MCU shall we use?<br>
With the concept of [SDGs(Sustainable Development Goals)](https://en.wikipedia.org/wiki/Sustainable_Development_Goals) **MainStream** shall be good choice. **C0/G0/F0/F1/G4/F3**<br>
[Stm32 line-up](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)

- Even better if we could use a commercial IDE for free!<br>
[Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)

- Enough space **Flash, RAM** would make us smile.<br>
![NucleoSeries_C0G0F0](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/NucleoSeries_C0G0F0.png)<br>

- PC<br>
It would be nice if Stm32 Cube IDE could be driven. <br>
Even the trainer's antique ([Latitude5285](https://japancatalog.dell.com/pd/latitude-5285-laptop.html), Intel(R) Core(TM) i5-2400 CPU @ 3.10GHz 3.10 GHz) can barely work, but if it's a recent one, it won't be a problem.
- Application<br>
The following applications are required for practical training.<br>
There are no licenses required, so be sure to install the latest version.<br>
ST Badge's CubeIDE shall be ***1.16.0***, which does not have a minor indication.
  - [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
  - [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
  - [![Winmerge](https://img.shields.io/badge/Winmerge-brightgreen?style=flat
)](https://winmerge.org/)
  - [![Stm Cube IDE](https://img.shields.io/badge/Stm-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)　***1.16.0***
  - [![draw.io](https://img.shields.io/badge/Drawio-brightgreen?style=flat&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)
  - [![Doxygen](https://img.shields.io/badge/Doxygen-brightgreen?style=flat)](https://www.doxygen.nl/)
  - [![Graphviz](https://img.shields.io/badge/Graphviz-brightgreen?style=flat)](https://graphviz.org/)

</details>

<div id="Part1_Basic"></div>
<details open>
<summary><font size="5"><b>Part.1[Basic]</b></font></summary>

- [TOC](#toc)<br>
- [1. What is MS](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)
  - Trends
  - Market
  - MCU basic features
- [2. Hello MCU](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md)
  - At first? ***Git!!***
  - Hello Cube
  - How to debug
- [3. Process and Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md)
  - Development Process
  - Organization

</details>

<div id="Part2_Implementation"></div>
<details open>
<summary><font size="5"><b>Part.2[Implementation]</b></font></summary>

- [TOC](#toc)<br>
- [Wok flow on Github](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)
- [Requirement Analysis](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis.md)
  - System Requirement
  - System Requirement Specification
  - Software Requirement Specification
- [Software Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md)
  - HLD (High Level Design)
  - Sequence Diagram
  - State Machine Diagram
- [Software Implementation](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md)
  - Coding Rules
  - Doxygen
  - Event Driven Design Pattern
</details>

<div id="Tip001"></div>
<details open>
<summary><font size="5"><b>Tip001: Show me the Badge</b></font></summary>

- [TOC](#toc)<br>
- Creating beautiful icons is quite difficult.
- Let's have you create a Badge using this as a reference.<br>
![Show-me-the-badge](https://github.com/gtuja/CSC_MS/blob/main/Resources/Tips/tip001_001_shields_io_static_badge.png)<br>
- This document is also used in various ways, such as displaying the latest tags, navigation, and software links.

</details>
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md) [![Part.2](https://img.shields.io/badge/Part.2-Implementation-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)

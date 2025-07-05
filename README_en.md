![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md) [![Part.2](https://img.shields.io/badge/Part.2-Implementation-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)

# MCU development from scratch

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [Concept](#Concept)
- [Trainer](#Trainer)
- [Preparation](#Preparation)
- [Part.1[Basic]](#Part1_Basic)
- [Part.2[Implementation]](#Part2_Implementation)
- [EX. Show me the Badge](#Exercise)
- [Reference](#Reference)
- [History](#history)

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>Concept</b></font></summary>

- This program aims to provide a guide for those who are interested in MS development but are worried about ***where to start***.
- Regarding MS development environment ([Part.1[Basic]](Part1_Basic)) and Requirements, product development ([Part.2[Implementation]](#Part2_Implementation))
follow the steps in order and proceed.
- We're gonna practice a simple project at the [Part.2[Implementation]](#Part2_Implementation), with [Process and Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md) on the [Part.1[Basic]](#Part1_Basic).<br><br>
![gantt_chart_deliverables_by_division](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/gantt_chart_deliverables_by_division.png)
- Keep in mind [Golden ratio](https://en.m.wikipedia.org/wiki/Golden_ratio) and [Affordance](https://en.m.wikipedia.org/wiki/Affordance), divide and conquer with [Occam's razor](https://en.m.wikipedia.org/wiki/Occam%27s_razor). 

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>Trainer</b></font></summary>

- [TOC](#toc)
- Seho Seo, Korean, 50s
- Graduated from Pusan University, Department of Computer Science.
- Working as a MS engineer for 21 years in Japan, in the filed of home appliance, FA  and automotive, etc.
- Interested in fishing, speakers, Costco, etc.

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>Preparation</b></font></summary>

- [TOC](#toc)
- In this program, we're gonna practice with evaluation board.
- (Q) Which supplier
- (A) In terms of growth, **[ST](https://www.st.com/content/st_com/en.html)**<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png)
- (A) [Top 5 Manufacturers in the MCU Market](https://www.onerivertronics.com/a/43018.html)
- (A) [Top 5 MCU Manufacturers View for the Development of the Microcontroller Market](https://www.hardfindelec.com/a/76030.html)
- (Q) Which MCU?
- (A) [SDGs!](https://en.wikipedia.org/wiki/Sustainable_Development_Goals) **[MainStream:C0/G0/F0/F1/G4/F3](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)**
- (Q) [Toolchain?](https://en.wikipedia.org/wiki/Toolchain)
- (A) **[Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)**<br>
- (A) The annual license fee for Keil MDK is 200,000 to 400,000 Yen, who could afford to it? [Keil vs GCC](https://stackoverflow.com/questions/1226401/keil-vs-gcc-for-arm7)
- (A) Being able to use it for free is a great benefit, so let's use it for future big projects.
- (A) In this program we're gonna use CubeIDE, cause it's easy to start.
- (Q) Flash, RAM?
- (A) **[NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)**<br>
[![NucleoSeries_C0G0F0](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/NucleoSeries_C0G0F0.png)](https://www.marutsu.co.jp/pc/i/40719714/)
- PC
  - OS : Windows 10, 11
  - CPU : >= Intel Core-i5-7200U (7th 2017/01)
  - RAM : >= 8GB
  - SSD : >= 256GB, Git(50MB), TortoiseGit(50MB), CubeIDE(2GB)
- USB cable : micro-B <-> [Type-A, Type-C]
- Wifi
- [Github account](https://github.com)
- [STM account](https://www.st.com)
- Application
- The latest version is always a good choice, but let's use CubeIDE with ***1.16.0***, which does not have any minor features.
  - [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
  - [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
  - [![Stm Cube IDE](https://img.shields.io/badge/Stm-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)　***1.16.0***
  - Microsoft Office [Excel, Powerpoint, etc.] *option

</details>

<div id="Part1_Basic"></div>
<details open>
<summary><font size="5"><b>Part.1[Basic]</b></font></summary>

- [TOC](#toc)
- [1. What is MS](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)
  - [Background](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Background)
  - [Trends](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Trends)
  - [Market](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Market)
  - [Basic_Features](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Basic_Features)
- [2. Hello MCU](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md)
  - [At first? Git!!](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#At_first_Git)
  - [EX.1 Show me your Git](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#Exercise1)
  - [EX.2 Hello Cube](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#Exercise2)
  - [EX.3 Show me the Clock](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#Exercise3)
- [3. Work Flow & Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md)
  - [Work Flow](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md#Work_Flow)
  - [Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md#Organization)
  - [EX. Show me the PWM](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md#Exercise)

</details>

<div id="Part2_Implementation"></div>
<details open>
<summary><font size="5"><b>Part.2[Implementation]</b></font></summary>

- [TOC](#toc)
- [1. Workflow on the Github](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)
  - [EX. Show me your Github](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md#Exercise)
- [2. Requirement Analysis](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis_en.md)
  - [What is requirements](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis_en.md#what_is_requirements)
  - [Project ALM](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis_en.md#project_alm)
  - [EX. Show me the Log](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis_en.md#Exercise)
- [3. Software Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign_en.md)
  - [HLD(High Level Design)](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign_en.md#HLD)
  - [Detailed Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign_en.md#Detailed_Design)
  - [EX. Hello draw.io](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign_en.md#Exercise)
- [4. Software Implementation](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation_en.md)
  - [Stm32CubeIDE](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation_en.md#Stm32CubeIDE)
  - [Coding Rules](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation_en.md#coding_rules)
  - [EX. Show me the ISR](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation_en.md#Exercise)  
  - [End of Part.2](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation_en.md#end_of_part2)

</details>

<div id="Exercise"></div>
<details open>
<summary><font size="5"><b>EX. Show me the Badge</b></font></summary>

- [TOC](#toc)<br>
- Creating beautiful icons is quite difficult.
- Let's create some Badges with below as a reference.<br>
![Show-me-the-badge](https://github.com/gtuja/CSC_MS/blob/main/Resources/Tips/tip001_001_shields_io_static_badge.png)<br>
- This document is also used in various ways, such as displaying the latest tags, navigation, and software links.

</details>

<div id="Reference"></div>
<details open>
<summary><font size="5"><b>Reference</b></font></summary>

- [TOC](#toc)
- [NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)
- [Github](https://github.com)
- [STM](https://www.st.com)
- [Shield.io](https://shields.io)
- [Simple icon](https://simpleicons.org/)
- [Lychee-Waterfall model](https://lychee-redmine.jp/blogs/project/biginner_and_waterfallmodel/)

</details>

<div id="history"></div>
<details open>
<summary><font size="5"><b>History</b></font></summary> 

- v0.1 2024/09/14 Seho.Seo Brand new document.
- v0.2 2024/09/15 Seho.Seo Remove Part3, it might be rescheduled.
- v0.3 2024/09/22 Seho.Seo Deal with features, multi-language, shield-io badges and improve readability overall contents.
- v0.6 2024/11/04 Seho.Seo Update overall contents, e.g., exercises.
- v0.7 2025/01/29 Seho.Seo Update contents and release v0.7.
- v0.8 2025/07/05 Seho.Seo Update README, Part1 and Part2.
</details>
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md) [![Part.2](https://img.shields.io/badge/Part.2-Implementation-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)

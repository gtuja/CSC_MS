![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)
[![Part.2](https://img.shields.io/badge/Part.2-Design-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis_en.md)
[![Part.3](https://img.shields.io/badge/Part.3-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD_en.md)
[![Part.4](https://img.shields.io/badge/Part.4-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD_en.md)

# MS development from scratch

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [Concept](#Concept)
- [Trainer](#Trainer)
- [Preparation](#Preparation)
- [Overview](#Overview)
- [Reference](#Reference)
- [History](#history)

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>Concept</b></font></summary>

- This program aims to provide trainee, who are interested in MS development but not sure ***where to start***, with a guide.
- Keep in mind [Golden ratio](https://en.m.wikipedia.org/wiki/Golden_ratio) and [Affordance](https://en.m.wikipedia.org/wiki/Affordance), divide and conquer with [Occam's razor](https://en.m.wikipedia.org/wiki/Occam%27s_razor). 

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>Trainer</b></font></summary>

- [TOC](#toc)
- Seho Seo, Korean, 50s
- Graduated from Pusan University, Department of Computer Science at 1999.
- Working as a MS engineer for 22 years in Japan, in the filed of home appliance, FA and automotive, etc.
- Interested in fishing, speakers, Costco, etc.
</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>Preparation</b></font></summary>

- [TOC](#toc)
- In this program, we're gonna practice with evaluation board.
- **(Q) Which supplier?**
- (A) In terms of growth, **[ST](https://www.st.com/content/st_com/en.html)**<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png)
- (A) [Top 5 Manufacturers in the MCU Market](https://www.onerivertronics.com/a/43018.html)
- (A) [Top 5 MCU Manufacturers View for the Development of the Microcontroller Market](https://www.hardfindelec.com/a/76030.html)
- **(Q) Which MCU?**
- (A) [SDGs!](https://en.wikipedia.org/wiki/Sustainable_Development_Goals) **[MainStream:C0/G0/F0/F1/G4/F3](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)**
- **(Q) [Toolchain?](https://en.wikipedia.org/wiki/Toolchain)**
- (A) [Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)<br>
- (A) The annual license fee for Keil MDK is 200,000 to 400,000 Yen, who could afford to it? [Keil vs GCC](https://stackoverflow.com/questions/1226401/keil-vs-gcc-for-arm7)
- (A) Being able to use it for free is a great benefit, so let's use it for the big projects.
- (A) In this program we're gonna use CubeIDE, cause it's easy to start.
- **(Q) Flash, RAM**?
- (A) [NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)<br>
[![NucleoSeries_C0G0F0](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/NucleoSeries_C0G0F0.png)](https://www.marutsu.co.jp/pc/i/40719714/)
- **PC** 
  - OS : Windows 10, 11
  - CPU : >= Intel Core-i5-7200U (7th 2017/01)
  - RAM : >= 8GB
  - SSD : >= 256GB, Git(50MB), TortoiseGit(50MB), CubeIDE(2GB)
- **USB cable** : micro-B <-> [Type-A, Type-C]
- **Wifi**
- **[Github account](https://github.com)**
- **[STM account](https://www.st.com)**
- **Application**
  - The latest version is always a good choice.
  - [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
  - [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
  - [![Stm Cube IDE](https://img.shields.io/badge/Stm-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
  - Microsoft Office [Excel, Powerpoint, etc.] *option
</details>

<div id="Overview"></div>
<details open>
<summary><font size="5"><b>Overview</b></font></summary>

- [TOC](#toc)
- ![MSDFS Overview](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/README_Diagrams-Overview.drawio.png)
- [Part1. 基本編](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
  - [1.1. What is MS](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)
    - [Background](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Background)
    - [Trends](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Trends)
    - [Market](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Market)
    - [Basic_Features](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md#Basic_Features)
  - [1.2. Hello MCU](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md)
    - [At first? Git!!](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#At_first_Git)
    - [EX.1 Show me your Git](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#Exercise1)
    - [EX.2 Hello Cube](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#Exercise2)
    - [EX.3 Show me the Clock](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md#Exercise3)
  - [1.3. Work Flow & Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md)
    - [Work Flow](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md#Work_Flow)
    - [Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md#Organization)
    - [Github](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md#Github)
- [Part2. Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis_en.md)
  - [2.1. Requirement Analysis](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis_en.md)
    - [What is requirements?](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis_en.md#what_is_requirements)
    - [The project ALM](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis_en.md#project_alm)
  - [2.2 Software Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign_en.md)
    - [HWD (HardWare Design)](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign_en.md#HWD)
    - [HLD(High Level Design)](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign_en.md#HLD)
    - [Detailed Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign_en.md#Detailed_Design)
- [Part3. Planning(TBD)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)
- [Part4. Implementation(TBD)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)
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
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)
[![Part.2](https://img.shields.io/badge/Part.2-Design-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis_en.md)
[![Part.3](https://img.shields.io/badge/Part.3-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD_en.md)
[![Part.4](https://img.shields.io/badge/Part.4-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD_en.md)

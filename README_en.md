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
- [Tip : Show me the Badge](#Tip001)

</details>

<div id="history"></div>
<details open>
<summary><font size="5"><b>History</b></font></summary> 

- [TOC](#toc)
- v0.1 2024/09/14 Seho.Seo Brand new document.
- v0.2 2024/09/15 Seho.Seo Remove Part3, it might be rescheduled.
- v0.3 2024/09/22 Seho.Seo Deal with features, multi-language, shield-io badges and improve readability overall contents.

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>Concept</b></font></summary>

- [TOC](#toc)
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
- Working as a MS engineer for 21 years in Japan, home appliance, FA  and automotive fields.
- Hobbies are fishing, speakers, Costco...

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>Preparation</b></font></summary>

- [TOC](#toc)
- In this program, we're gonna practice with evaluation board.
- Which supplier? potential for growth! **[ST](https://www.st.com/content/st_com/en.html)**<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png)<br>
[Top 5 Manufacturers in the MCU Market](https://www.onerivertronics.com/a/43018.html)<br>
[Top 5 MCU Manufacturers View for the Development of the Microcontroller Market](https://www.hardfindelec.com/a/76030.html)
- Which MCU? [SDGs!](https://en.wikipedia.org/wiki/Sustainable_Development_Goals) **[MainStream:C0/G0/F0/F1/G4/F3](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)**<br>
- [Toolchain?](https://en.wikipedia.org/wiki/Toolchain) **[Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)**<br>
\- The annual license fee for Keil MDK is 200,000 to 400,000 Yen, who could afford to it? [Keil vs GCC](https://stackoverflow.com/questions/1226401/keil-vs-gcc-for-arm7)<br>
\- Being able to use it for free is a huge benefit, so let's use it for future big projects!<br>
\- In this program we're gonna use CubeIDE, cause it's easy to start.<br>

- Flash, RAM? **[NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)**<br>
![NucleoSeries_C0G0F0](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/NucleoSeries_C0G0F0.png)<br>
[marutsu](https://www.marutsu.co.jp/pc/i/40719714/)
- PC
- Wifi
- [Github account](https://github.com)
- [STM account](https://www.st.com)
- Application<br>
The latest version is always a good choice, but let's use CubeIDE with ***1.16.0***, which does not have any minor features.<br>
\- [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)<br>
\- [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)<br>
\- [![Winmerge](https://img.shields.io/badge/Winmerge-brightgreen?style=flat)](https://winmerge.org/)<br>
\- [![Stm Cube IDE](https://img.shields.io/badge/Stm-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)　***1.16.0***<br>
\- [![draw.io](https://img.shields.io/badge/Drawio-brightgreen?style=flat&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)<br>
\- [![Doxygen](https://img.shields.io/badge/Doxygen-brightgreen?style=flat)](https://www.doxygen.nl/)<br>
\- [![Graphviz](https://img.shields.io/badge/Graphviz-brightgreen?style=flat)](https://graphviz.org/)<br>

</details>

<div id="Part1_Basic"></div>
<details open>
<summary><font size="5"><b>Part.1[Basic]</b></font></summary>

- [TOC](#toc)
- [1. What is MS](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)<br>
\- Trends<br>
\- Market<br>
\- MCU basic features<br>
- [2. Hello MCU](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU_en.md)<br>
\- At first? ***Git!!***<br>
\- Hello Cube<br>
\- Debug printf<br>
- [3. Process and Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization_en.md)<br>
\- Development Process<br>
\- Organization<br>

</details>

<div id="Part2_Implementation"></div>
<details open>
<summary><font size="5"><b>Part.2[Implementation]</b></font></summary>

- [TOC](#toc)
- [Wok flow on Github](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)<br>
- [Requirement Analysis](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis_en.md)<br>
\- System Requirement<br>
\- System Requirement Specification<br>
\- Software Requirement Specification<br>
- [Software Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign_en.md)<br>
\- HLD(High Level Design)<br>
\- Detailed Design<br>
- [Software Implementation](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation_en.md)<br>
\- Stm32CubeIDE<br>
\- Coding Rules<br>
\- End of Part.2<br>

</details>

<div id="Tip001"></div>
<details open>
<summary><font size="5"><b>Tip : Show me the Badge</b></font></summary>

- [TOC](#toc)<br>
- Creating beautiful icons is quite difficult.
- Let's create some Badges with below as a reference.<br>
![Show-me-the-badge](https://github.com/gtuja/CSC_MS/blob/main/Resources/Tips/tip001_001_shields_io_static_badge.png)<br>
- This document is also used in various ways, such as displaying the latest tags, navigation, and software links.

</details>
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md) [![Part.2](https://img.shields.io/badge/Part.2-Implementation-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/Language-%E6%97%A5%E6%9C%AC%E8%AA%9E-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README.md)
[![Part.1](https://img.shields.io/badge/Part.1-Basic-brightgreen)]((https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS_en.md)) [![Part.2](https://img.shields.io/badge/Part.2-Implementation-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub_en.md)

# MCU development from scratch

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [History](#history)
- [Concept](#Concept)
- [Trainer](#Trainer)
- [Preparation](#Preparation)
- [Part1[Basic]](#Part1_Basic)
- [Part2[Implementation]](#Part2_Implementation)

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
- Regarding **MS development environment** ([Part1[Basic]](Part1_Basic)) and **Requirements, product development** ([Part2[Implementation]](#Part2_Implementation))
follow the steps in order and proceed.
- We're gonna practice a simple project at the [Part2[Implementation]](#Part2_Implementation), with [Process and Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md) on the [Part1[Basic]](#Part1_Basic).<br><br>
![gantt_chart_deliverables_by_division](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/gantt_chart_deliverables_by_division.png)
- Keep in mind [Golden ratio](https://en.m.wikipedia.org/wiki/Golden_ratio) and [Affordance](https://en.m.wikipedia.org/wiki/Affordance), divide and conquer with [Occam's razor](https://en.m.wikipedia.org/wiki/Occam%27s_razor). 

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>Trainer</b></font></summary>

- [TOC](#toc)<br>
- Seho Seo, Korean, 50s
- Graduated from Pusan University, Department of Computer Science.
- Working as a MS engineer for 21 years in Japan, home appliance, FA, and automotive fields.
- Hobbies are fishing, speakers, Costco...

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>Preparation</b></font></summary>

- [TOC](#toc)<br>
- Evaluation board：[Stm32 NUCLEO](https://www.st.com/ja/evaluation-tools/stm32-nucleo-boards.html), [Akizuki](https://akizukidenshi.com/catalog/goods/search.aspx?keyword=nucleo&ct=&goods=&number=&name=&min_price=2800&max_price=&yy_min_releasedt=&mm_min_releasedt=&dd_min_releasedt=&yy_max_releasedt=&mm_max_releasedt=&dd_max_releasedt=&last_sdt=&gt=&goods_specification=&seq=popd&maker_name=&search=%E6%A4%9C%E7%B4%A2%E3%81%99%E3%82%8B&variation=)
- PC
- Application
  - [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
  - [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
  - [![Winmerge](https://img.shields.io/badge/Winmerge-brightgreen?style=flat
)](https://winmerge.org/)
  - [![Stm](https://img.shields.io/badge/Stm-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
  - [![draw.io](https://img.shields.io/badge/Drawio-brightgreen?style=flat&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)
  - [![Doxygen](https://img.shields.io/badge/Doxygen-brightgreen?style=flat)](https://www.doxygen.nl/)
  - [![Graphviz](https://img.shields.io/badge/Graphviz-brightgreen?style=flat)](https://graphviz.org/)

</details>

<div id="Part1_Basic"></div>
<details open>
<summary><font size="5"><b>Part1[Basic]</b></font></summary>

- [TOC](#toc)<br>
- [What is MS](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
  - Trends
  - Market
  - MCU basic features
- [Hello MCU](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md)
  - At first? ***Git!!***
  - Hello Cube
  - How to debug
- [Process and Organization](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)
  - Development Process
  - Organization

</details>

<div id="Part2_Implementation"></div>
<details open>
<summary><font size="5"><b>Part2[Implementation]</b></font></summary>

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

<div id="Reference"></div>
<details open>
<summary><font size="5"><b>Reference</b></font></summary>

- [TOC](#toc)<br>
[![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
[![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
[![Github](https://img.shields.io/badge/Github-brightgreen?style=flat&logo=github&logoColor=%23181717&labelColor=white)](https://github.com/)
[![Winmerge](https://img.shields.io/badge/Winmerge-brightgreen?style=flat
)](https://winmerge.org/)
[![Markdown](https://img.shields.io/badge/Markdown-brightgreen?style=flat&logo=markdown&logoColor=%23000000&labelColor=white)](https://daringfireball.net/projects/markdown/)
[![Stm](https://img.shields.io/badge/Stm-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
[![FreeRTOS](https://img.shields.io/badge/FreeRTOS-brightgreen?style=flat)](https://www.freertos.org/)
[![draw.io](https://img.shields.io/badge/Drawio-brightgreen?style=flat&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)
[![Doxygen](https://img.shields.io/badge/Doxygen-brightgreen?style=flat)](https://www.doxygen.nl/)
[![Graphviz](https://img.shields.io/badge/Graphviz-brightgreen?style=flat)](https://graphviz.org/)

</details>

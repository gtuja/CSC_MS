![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/%E8%A8%80%E8%AA%9E-English-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README_en.md)
[![Part.1](https://img.shields.io/badge/Part.1-%E5%9F%BA%E6%9C%AC%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
[![Part.2](https://img.shields.io/badge/Part.2-%E8%A8%AD%E8%A8%88%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis.md)
[![Part.3](https://img.shields.io/badge/Part.3-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)
[![Part.4](https://img.shields.io/badge/Part.4-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)

# ゼロからのマイコン開発

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [コンセプト](#Concept)
- [トレーナー](#Trainer)
- [事前準備](#Preparation)
- [概要](#Part1_Overview)
- [Reference](#Reference)
- [変更履歴](#history)

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>コンセプト</b></font></summary>

- このコンテンツはMS開発にて､何から手を付ければいいのかを悩む方への一つの提案です。<br><br>
![MSDFS Concept](https://github.com/gtuja/CSC_MS/blob/main/Resources/Part1/Part1_Diagrams-Concept.drawio.png)<br>
- [**Golden ratio**](https://en.m.wikipedia.org/wiki/Golden_ratio)と[**Affordance**](https://en.m.wikipedia.org/wiki/Affordance)を念頭に入れ、[**Occam's razor**](https://en.m.wikipedia.org/wiki/Occam%27s_razor)を手に持って切り開こう！

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>トレーナー</b></font></summary>

- [TOC](#toc)
- Seho Seo, 韓国, 51 **[4(S), 3(M), 3(P), 22 => 8(T), 4(F), 10(T)]**
- 釜山大学・電子計算学科卒
- 2003年に来日してから22年間、MSエンジニアとして、家電・FA・モビリティ分野で活動中？
- 趣味は釣り・スピーカー・コストコ巡りなど

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>事前準備</b></font></summary>

- [TOC](#toc)
- このプログラムではMCU開発を実習しますので、MCUを載せている評価ボードが必要です。
- **(Q) どのサプライヤーを選ぶのか？**
- (A) 伸びしろからは[ST](https://www.st.com/content/st_com/en.html)でしょう。<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png)<br>
- [Top 5 Manufacturers in the MCU Market](https://www.onerivertronics.com/a/43018.html)
- [Top 5 MCU Manufacturers View for the Development of the Microcontroller Market](https://www.hardfindelec.com/a/76030.html)
- **(Q) どのマイコンにするのか？**
- (A) [SDGs](https://en.wikipedia.org/wiki/Sustainable_Development_Goals)的には[MainStream:C0/G0/F0/F1/G4/F3](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)でしょう。
- **(Q) [Toolchain](https://en.wikipedia.org/wiki/Toolchain)はどれにするか？**
- (A) [Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)はいいですね。
- (A) Keil MDKの年間ライセンス費用は20~40万円で、個人での購入は絶望的です。[Keil vs GCC](https://stackoverflow.com/questions/1226401/keil-vs-gcc-for-arm7)
- (A) これをタダで使えるのはかなりのメリットありで、いずれ訪れる大きなプロジェクトでの活躍？のためにも覚えておきたいですが、本プログラムはゼロからですので、分かりやすいStm32CubeIDEの[GNU Toolchain](https://en.wikipedia.org/wiki/GNU_toolchain)を使います。
- (A) MDK環境に対しては「３からのMCU開発」？ぐらいでしょう。
- **(Q) Flash, RAMサイズはどれぐらい必要か？**
- (A) 大は小を兼ねるので[NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)でしょう。<br>
[![NucleoSeries_C0G0F0](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/NucleoSeries_C0G0F0.png)](https://www.marutsu.co.jp/pc/i/40719714/)<br>
- **PC**
  - OS : Windows 10, 11
  - CPU : >= Intel 第7世代Core-i5-7200U (2017年1月)
  - RAM : >= 8GB
  - SSD : >= 256GB, Git(50MB), TortoiseGit(50MB), CubeIDE(2GB)
- **USB cable**
  - micro-B <-> [Type-A, Type-C]
- **Wifi**
- **[Githubアカウント](https://github.com)**
- **[STMアカウント](https://www.st.com)**
- **Applications**
  - [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
  - [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
  - [![Stm Cube IDE](https://img.shields.io/badge/CubeIDE-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
  - Microsoft Office [Excel, Powerpoint, etc.] *option

</details>

<div id="Part1_Overview"></div>
<details open>
<summary><font size="5"><b>概要</b></font></summary>

- [TOC](#toc)
- [Part.1[基本編]](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
  - [1.1. MSとは](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
    - [背景](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Background)
    - [トレンド](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Trends)
    - [市場](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Market)
    - [マイコンの基本](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Basic_Features)
  - [1.2. 百考は一行に如かず](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md)
    - [最初は? Git!!](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#At_first_Git)
    - [EX.1 Show me your Git](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#Exercise1)
    - [EX.2 Hello Cube](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#Exercise2)
    - [EX.3 Show me the Clock](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#Exercise3)
  - [1.3. 業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)
    - [業務プロセス](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md#WorkFlow)
    - [組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md#Organization)
    - [Github上のプロジェクト管理](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md#Github)
- [Part.2[設計編]](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis.md)
  - [2.1. 要求分析](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis.md)
    - [要求とは](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis.md#what_is_requirements)
    - [Project ALM](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis.md#project_alm)
  - [2.2 ソフトウエアデザイン](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign.md)
    - [HLD(High Level Design)](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign.md#HLD)
    - [Detailed Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.SoftwareDesign.md#Detailed_Design)
- [Part.3[実装編(TBD)]](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)
- [Part.3[評価編(TBD)]](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)
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
<summary><font size="5"><b>変更履歴</b></font></summary> 

- v0.1 2024/09/14 Seho.Seo Brand new document.
- v0.2 2024/09/15 Seho.Seo Remove Part3, it might be rescheduled.
- v0.3 2024/09/22 Seho.Seo Deal with features, multi-language, shield-io badges and improve readability overall contents.
- v0.6 2024/11/04 Seho.Seo Update overall contents, e.g., exercises.
- v0.7 2025/01/29 Seho.Seo Update contents and release v0.7.
- v0.8 2025/07/05 Seho.Seo Update README, Part1 and Part2.
</details>
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/%E8%A8%80%E8%AA%9E-English-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README_en.md)
[![Part.1](https://img.shields.io/badge/Part.1-%E5%9F%BA%E6%9C%AC%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
[![Part.2](https://img.shields.io/badge/Part.2-%E8%A8%AD%E8%A8%88%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.RequirementAnalysis.md)
[![Part.3](https://img.shields.io/badge/Part.3-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)
[![Part.4](https://img.shields.io/badge/Part.4-TBD-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Resources/TBD.md)

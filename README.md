![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/%E8%A8%80%E8%AA%9E-English-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README_en.md)
[![Part.1](https://img.shields.io/badge/Part.1-%E5%9F%BA%E6%9C%AC%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md) [![Part.2](https://img.shields.io/badge/Part.2-%E5%AE%9F%E8%A3%85%E5%A4%89-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)

# ゼロからのMCU開発

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [変更履歴](#history)
- [コンセプト](#Concept)
- [トレーナー](#Trainer)
- [事前準備](#Preparation)
- [Part.1[基本編]](#Part1_Basic)
- [Part.2[実装編]](#Part2_Implementation)
- [EX. Show me the Badge](#Exercise)
- [Reference](#Reference)

</details>

<div id="history"></div>
<details open>
<summary><font size="5"><b>変更履歴</b></font></summary> 

- v0.1 2024/09/14 Seho.Seo Brand new document.
- v0.2 2024/09/15 Seho.Seo Remove Part3, it might be rescheduled.
- v0.3 2024/09/22 Seho.Seo Deal with features, multi-language, shield-io badges and improve readability overall contents.
- v0.6 2024/11/04 Seho.Seo Update overall contents, e.g., exercises.
  
</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>コンセプト</b></font></summary>

- このプログラムはMS開発に興味はあるが､何から手を付ければいいのかを悩む方への一つの提案です。
- [Part.1[基本編]](Part1_Basic)では、開発環境を構築します。
- [Part.2[実装編]](#Part2_実装編)では、簡単なシステム要求を定義してから、開発業務プロセスを実習しましょう。
- 要求分析・ソフトウエア設計・ソフトウエア開発を順に追って行います。
- [Part.1[基本編]](#Part1_Basic)の[業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)を念頭において、進めていきましょう。<br>
![gantt_chart_deliverables_by_division](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/gantt_chart_deliverables_by_division.png)
- [Golden ratio](https://en.m.wikipedia.org/wiki/Golden_ratio)と[Affordance](https://en.m.wikipedia.org/wiki/Affordance)を念頭に入れ、[Occam's razor](https://en.m.wikipedia.org/wiki/Occam%27s_razor)を手に持って切り開こう！

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>トレーナー</b></font></summary>

- [TOC](#toc)
- Seho Seo, 韓国, 50s
- 釜山大学・電子計算学科卒
- 2003年に来日してから21年間、MSエンジニアとして、家電・FA・モビリティ分野で活動中？
- 趣味は釣り・スピーカー・コストコ巡りなど

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>事前準備</b></font></summary>

- [TOC](#toc)
- このプログラムではMCU開発を実習しますので、MCUを載せている評価ボードが必要です。
- (Q) どのサプライヤーを選ぶのか？
- (A) 伸びしろからは[ST](https://www.st.com/content/st_com/en.html)でしょう。<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png)<br>
- [Top 5 Manufacturers in the MCU Market](https://www.onerivertronics.com/a/43018.html)
- [Top 5 MCU Manufacturers View for the Development of the Microcontroller Market](https://www.hardfindelec.com/a/76030.html)
- (Q) どのマイコンにするのか？
- (A) [SDGs](https://en.wikipedia.org/wiki/Sustainable_Development_Goals)的には[MainStream:C0/G0/F0/F1/G4/F3](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)でしょう。
- (Q) [Toolchain](https://en.wikipedia.org/wiki/Toolchain)はどれにするか？
- (A) [Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)はいいですね。
- (A) Keil MDKの年間ライセンス費用は20~40万円で、個人での購入は絶望的です。[Keil vs GCC](https://stackoverflow.com/questions/1226401/keil-vs-gcc-for-arm7)
- (A) これをタダで使えるのはかなりのメリットありで、いずれ訪れる大きなプロジェクトでの活躍？のためにも覚えておきたいですが、本プログラムはゼロからですので、分かりやすいStm32CubeIDEの[GNU Toolchain](https://en.wikipedia.org/wiki/GNU_toolchain)を使います。
- (A) MDK環境に対しては「３からのMCU開発」？ぐらいでしょう。
- (Q) Flash, RAMサイズはどれぐらい必要か？
- (A) 大は小を兼ねるので[NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)でしょう。<br>
[![NucleoSeries_C0G0F0](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/NucleoSeries_C0G0F0.png)](https://www.marutsu.co.jp/pc/i/40719714/)<br>
- PC
- USB cable : micro-B <-> [Type-A, Type-C]
- Wifi
- [Githubアカウント](https://github.com)
- [STMアカウント](https://www.st.com)
- Applications
- 基本的には最新版でOKですが、ST CubeIDEだけはマイナがついてない1.16.0で統一しましょう。
  - [![Git](https://img.shields.io/badge/Git-brightgreen?style=flat&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
  - [![TortoiseGit](https://img.shields.io/badge/TortoiseGit-brightgreen?style=flat)](https://tortoisegit.org/)
  - [![Winmerge](https://img.shields.io/badge/Winmerge-brightgreen?style=flat)](https://winmerge.org/)
  - [![Stm Cube IDE](https://img.shields.io/badge/CubeIDE-brightgreen?style=flat&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
  - [![draw.io](https://img.shields.io/badge/Drawio-brightgreen?style=flat&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)
  - [![Doxygen](https://img.shields.io/badge/Doxygen-brightgreen?style=flat)](https://www.doxygen.nl/)
  - [![Graphviz](https://img.shields.io/badge/Graphviz-brightgreen?style=flat)](https://graphviz.org/)
  - Microsoft Office [Excel, Powerpoint, etc.] *option

</details>

<div id="Part1_Basic"></div>
<details open>
<summary><font size="5"><b>Part.1[基本編]</b></font></summary>

- [TOC](#toc)
- [1. MSとは](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
  - [背景](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Background)
  - [トレンド](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Trends)
  - [市場](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Market)
  - [マイコンの基本](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md#Basic_Features)
- [2. 百考は一行に如かず](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md)
  - [最初は? Git!!](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#At_first_Git)
  - [EX.1 Show me your Git](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#Exercise1)
  - [EX.2 Hello Cube](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#Exercise2)
  - [EX.3 Show me the Clock](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md#Exercise3)
- [3. 業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)
  - [業務プロセス](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md#WorkFlow)
  - [組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md#Organization)
  - [EX. Show me the PWM](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md#Exercise)

</details>

<div id="Part2_Implementation"></div>
<details open>
<summary><font size="5"><b>Part.2[実装編]</b></font></summary>

- [TOC](#toc)
- [1. Github上のプロジェクト管理](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)
  - [EX. Show me your Github](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md#Exercise)
- [2. 要求分析](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis.md)
  - [要求とは](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis.md#what_is_requirements)
  - [Project ALM](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis.md#project_alm)
  - [EX. Show me the Log](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md#Exercise)
- [3. ソフトウエアデザイン](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md)
  - [HLD(High Level Design)](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md#HLD)
  - [Detailed Design](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md#Detailed_Design)
  - [EX. Hello draw.io](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md#Exercise)
- [4. ソフトウエア開発](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md)
  - [開発環境](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md#Stm32CubeIDE)
  - [コーディング規則](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md#coding_rules)
  - [EX. Show me the ISR](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md#Exercise)
  - [終わりに](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md#end_of_part2)
 
</details>

<div id="Exercise"></div>
<details open>
<summary><font size="5"><b>EX. Show me the Badge</b></font></summary>

- [TOC](#toc)
- 綺麗なアイコン作りはなかなか難しいものです。
- 下記マニュアル？を参考に自分Badgeを作って見ましょう。
- [Shield.io](https://shields.io), [Simple icon](https://simpleicons.org/)<br>
![Show-me-the-badge](https://github.com/gtuja/CSC_MS/blob/main/Resources/Tips/tip001_001_shields_io_static_badge.png)<br>
- このプログラムにも、最新タグの表示、ナビゲーション、ソフトウエアリンクなどにBadgeが活躍中？です。
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

</details>
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/%E8%A8%80%E8%AA%9E-English-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README_en.md)
[![Part.1](https://img.shields.io/badge/Part.1-%E5%9F%BA%E6%9C%AC%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md) [![Part.2](https://img.shields.io/badge/Part.2-%E5%AE%9F%E8%A3%85%E5%A4%89-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)

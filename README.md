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
- [Tip001: Show me the Badge](#Tip001)

</details>

<div id="history"></div>
<details open>
<summary><font size="5"><b>変更履歴</b></font></summary> 

- [TOC](#toc)<br>
- v0.1 2024/09/14 Seho.Seo Brand new document.
- v0.2 2024/09/15 Seho.Seo Remove Part3, it might be rescheduled.

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>コンセプト</b></font></summary>

- [TOC](#toc)<br>
- 本プログラムはMS開発に興味はあるが､**何から手を付ければいいのか**に悩む方への道しるべを示すことを目指します。
- [Part.1[基本編]](Part1_Basic)で、開発環境を構築し、[Part.2[実装編]](#Part2_実装編)では、要求分析、ソフトウエア設計、製品開発などを順に追って進めていきます。
- [Part.2[実装編]](#Part2_実装編)では[Part.1[基本編]](#Part1_Basic)の[業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)を意識しながら**実務感覚**で実習しましょう。<br><br>
![gantt_chart_deliverables_by_division](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/gantt_chart_deliverables_by_division.png)
- [Golden ratio](https://en.m.wikipedia.org/wiki/Golden_ratio)と[Affordance](https://en.m.wikipedia.org/wiki/Affordance)を念頭に入れ、[Occam's razor](https://en.m.wikipedia.org/wiki/Occam%27s_razor)を手に持って切り開こう！

</details>

<div id="Trainer"></div>
<details open>
<summary><font size="5"><b>トレーナー</b></font></summary>

- [TOC](#toc)<br>
- Seho Seo, 韓国, 50s
- 釜山大学の電子計算学科卒業
- MSエンジニアとして２１年間、家電、FA、自動車分野で勤務中
- 趣味は釣り、スピーカー、コストコ...

</details>

<div id="Preparation"></div>
<details open>
<summary><font size="5"><b>事前準備</b></font></summary>

- [TOC](#toc)<br>
- 評価ボード：[NUCLEO-G0B1RE](https://www.st.com/ja/evaluation-tools/nucleo-g0b1re.html)
- どのマイコンにするのか？<br>
![Leading MCU suppliers(2021)](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/Leading_MCU_Suppliers_2020_22021.png) ![STM32 MCUs](https://www.st.com/content/dam/category-pages/stm32-32-bit-arm-cortex-mcus/arm-cortex-mcu-portfolio-1.jpg)
- [分かりやすいIDE](https://www.st.com/content/st_com/ja/stm32cubemx.html)があればいい。
![](https://www.st.com/content/dam/st-crew/developer-zone/cube-mx/stm32cubemx-pinout-configuration.png)
- 無料で商用IDEも使えればいい！<br>
[Free Arm Keil MDK for STM32C0, STM32F0, STM32L0 and STM32G0](https://www.st.com/ja/partner-products-and-services/free-arm-keil-mdk-for-stm32c0-stm32f0-stm32l0-and-stm32g0.html)
- Flash, RAMに余裕があれば色々試せそう<br>

| Name | Flash(KB) | RAM(KB) | Price | Delivery(day) | Stock | Link | 
| --- | :---: | :---: | :---: | :---: | :---: | :---: | 
| NUCLEO-C031C6 | 32 | 12 | **2197** | 5 | 584 | [NUCLEO-C031C6](https://www.marutsu.co.jp/pc/i/43347410/)
| NUCLEO-C071RB | 128 | 24 | 2242 | 5 | 136 | [NUCLEO-C071RB](https://www.marutsu.co.jp/GoodsDetail.jsp?q=NUCLEO-C071RB&salesGoodsCode=48382034&shopNo=3)
| NUCLEO-F030R8 | 64 | 8 | 2201 | 5 | 663 | [NUCLEO-F030R8](https://www.marutsu.co.jp/pc/i/13537476/)
| NUCLEO-F070RB | 128 | 16 | 2201 | 5 | 71 | [NUCLEO-F070RB](https://www.marutsu.co.jp/pc/i/13537479/)
| NUCLEO-F072RB | 128 | 16 | 2201 | 5 | 304 | [NUCLEO-F072RB](https://www.marutsu.co.jp/pc/i/13537480/)
| NUCLEO-F091RC | 256 | 32 | 2201 | 5 | 80 | [NUCLEO-F091RC](https://www.marutsu.co.jp/pc/i/13537481/)
| NUCLEO-G070RB | 128 | 36 | 2201 | 5 | 315 | [NUCLEO-G070RB](https://www.marutsu.co.jp/pc/i/32060905/)
| NUCLEO-G071RB | 128 | 36 | 2201 | 5 | ***2200*** | [NUCLEO-G071RB](https://www.marutsu.co.jp/pc/i/31819503/)
| **NUCLEO-G0B1RE** | ***512*** | ***128*** | 2290 | 5 | 896 | [NUCLEO-G0B1RE](https://www.marutsu.co.jp/pc/i/40719714/)

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
<summary><font size="5"><b>Part.1[基本編]</b></font></summary>

- [TOC](#toc)<br>
- [1. MSとは](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
  - トレンド
  - 市場
  - マイコンの基本
- [2. 百考は一行に如かず](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md)
  - 最初は? ***Git!!***
  - Hello Cube
  - デバッグ
- [3. 業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)
  - 業務プロセス
  - 開発組織・役割・成果物

</details>

<div id="Part2_Implementation"></div>
<details open>
<summary><font size="5"><b>Part.2[実装編]</b></font></summary>

- [TOC](#toc)<br>
- [1. Github上のプロジェクト管理](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)
- [2. 要求分析](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis.md)
  - 製品要求
  - システム要求仕様
  - ソフトウエア要求仕様
- [3. ソフトウエアデザイン](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md)
  - HLD (High Level Design)
  - インラーフェス一覧
  - パッケージ図
  - シーケンス図
  - ステートマシン図
- [4. ソフトウエア開発](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md)
  - フォルダ構成
  - コーディング規則
  - Doxygen
  - タグ・配布

</details>

<div id="Tip001"></div>
<details open>
<summary><font size="5"><b>Tip001: Show me the Badge</b></font></summary>

- [TOC](#toc)<br>
- 綺麗なアイコン作りはなかなか難しいものです。
- 下記マニュアル？を参考にBadgeを作ってもらいましょう。
- [Shield.io](https://shields.io),  [Simpe icon](https://simpleicons.org/)<br>
![Show-me-the-badge](https://github.com/gtuja/CSC_MS/blob/main/Resources/Tips/tip001_001_shields_io_static_badge.png)<br>
- このドキュメントにも、最新タグの表示、ナビゲーション、ソフトウエアリンクなどにBadgeが使われています。

</details>
<br>

![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
[![Language](https://img.shields.io/badge/%E8%A8%80%E8%AA%9E-English-brightgreen)](https://github.com/gtuja/CSC_MS/blob/main/README_en.md)
[![Part.1](https://img.shields.io/badge/Part.1-%E5%9F%BA%E6%9C%AC%E7%B7%A8-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md) [![Part.2](https://img.shields.io/badge/Part.2-%E5%AE%9F%E8%A3%85%E5%A4%89-brightgreen
)](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)

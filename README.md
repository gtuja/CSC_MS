![latest tag](https://img.shields.io/github/v/tag/gtuja/CSC_MS.svg?color=brightgreen)
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

# ゼロからのMCU開発

<div id="toc"></div>
<details open>
<summary><font size="5"><b>Table of Contents</b></font></summary>

- [History](#history)
- [Concept](#Concept)
- [トレーナー](#トレーナー)
- [事前準備](#事前準備)
- [Part1[基本編]](#Part1_基本編)
- [Part2[実装編]](#Part2_実装編)

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
- 本プログラムはMS開発に興味はあるが、「**何から手を付ければいいのか**」に悩む方への道しるべを示すことを目指す。
- **MS開発環境構築**([Part1[基本編]](Part1_基本編))、**製品企画、要求分析、製品開発**([Part2[実装編]](#Part2_実装編))を順に追って教材を参考に進めていく。
- [Part2[実装編]](#Part2_実装編)以降は[Part1[基本編]](#Part1_基本編)、[業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)に則って**実務感覚**で実習する。<br><br>
![gantt_chart_deliverables_by_division](https://github.com/gtuja/CSC_MS/blob/main/Resources/README/gantt_chart_deliverables_by_division.png)
- README以外の教材は[英語で作成](https://english-club.jp/blog/english-world-population/)されている。
- Keep in mind [Golden ratio](https://en.m.wikipedia.org/wiki/Golden_ratio) and [Affordance](https://en.m.wikipedia.org/wiki/Affordance), divide and conquer with [Occam's razor](https://en.m.wikipedia.org/wiki/Occam%27s_razor). 

</details>

<div id="トレーナー"></div>
<details open>
<summary><font size="5"><b>トレーナー</b></font></summary>

- [TOC](#toc)<br>
- Seho Seo, 韓国, 50s
- 釜山大学の電子計算学科卒業
- MSエンジニアとして２１年間、家電、FA、自動車分野で勤務中
- 趣味は釣り、スピーカー、コストコ...

</details>

<div id="事前準備"></div>
<details open>
<summary><font size="5"><b>事前準備</b></font></summary>

- [TOC](#toc)<br>
- 評価ボード：[Stm32 NUCLEO](https://www.st.com/ja/evaluation-tools/stm32-nucleo-boards.html), [秋月](https://akizukidenshi.com/catalog/goods/search.aspx?keyword=nucleo&ct=&goods=&number=&name=&min_price=2800&max_price=&yy_min_releasedt=&mm_min_releasedt=&dd_min_releasedt=&yy_max_releasedt=&mm_max_releasedt=&dd_max_releasedt=&last_sdt=&gt=&goods_specification=&seq=popd&maker_name=&search=%E6%A4%9C%E7%B4%A2%E3%81%99%E3%82%8B&variation=)
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

<div id="Part1_基本編"></div>
<details open>
<summary><font size="5"><b>Part1[基本編]</b></font></summary>

- [TOC](#toc)<br>
- [MSとは](https://github.com/gtuja/CSC_MS/blob/main/Part1/1.What%20is%20MS.md)
  - トレンド
  - 市場
  - MCUの基本
- [百考は一行に如かず](https://github.com/gtuja/CSC_MS/blob/main/Part1/2.Hello%20MCU.md)
  - 最初は? ***Git!!***
  - Hello Cube
  - How to debug
- [業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)
  - 業務プロセス
  - 開発組織・役割・成果物

</details>

<div id="Part2_実装編"></div>
<details open>
<summary><font size="5"><b>Part2[実装編]</b></font></summary>

- [TOC](#toc)<br>
- [Github上のプロジェクト管理](https://github.com/gtuja/CSC_MS/blob/main/Part2/1.WorFlowOnGithub.md)
- [要求分析](https://github.com/gtuja/CSC_MS/blob/main/Part2/2.RequirementAnalysis.md)
  - 製品要求
  - システム要求仕様
  - ソフトウエア要求仕様
- [ソフトウエアデザイン](https://github.com/gtuja/CSC_MS/blob/main/Part2/3.SoftwareDesign.md)
  - HLD (High Level Design)
  - シーケンス図
  - ステートマシン図
- [ソフトウエア開発](https://github.com/gtuja/CSC_MS/blob/main/Part2/4.SoftwareImplementation.md)
  - コーディング規則
  - Doxygen
  - イイベントドリブンアーキテクチャ

</details>

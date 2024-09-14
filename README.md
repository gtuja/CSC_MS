[![GSL](https://img.shields.io/badge/GSL-Gtuja-baff13?style=plastic)](https://github.com/gtuja/Gsl)
[![Git](https://img.shields.io/badge/Git-baff13?style=plastic&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
[![TortoiseGit](https://img.shields.io/badge/TortoiseGit-baff13?style=plastic)](https://tortoisegit.org/)
[![Markdown](https://img.shields.io/badge/Markdown-baff13?style=plastic&logo=markdown&logoColor=%23000000&labelColor=white)](https://daringfireball.net/projects/markdown/)
[![Stm32 Cube](https://img.shields.io/badge/STM32Cube-baff13?style=plastic&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
[![FreeRTOS](https://img.shields.io/badge/FreeRTOS-baff13?style=plastic&logoColor=%23)](https://www.freertos.org/)
[![draw.io](https://img.shields.io/badge/draw.io-baff13?style=plastic&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)
[![doxygen](https://img.shields.io/badge/Doxygen-baff13?style=plastic)](https://www.doxygen.nl/)

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
- [Part3[評価編]](#Part3_評価編)
- [Reference](#Reference)

</details>

<div id="history"></div>
<details open>
<summary><font size="5"><b>History</b></font></summary> 

- [TOC](#toc)<br>
- v0.1 2024/09/14 S.Seo Brand-new document.

</details>

<div id="Concept"></div>
<details open>
<summary><font size="5"><b>Concept</b></font></summary>

- [TOC](#toc)<br>
- 本プログラムはMS開発に興味はあるが、「**何から手を付ければいいのか**」に悩む方への道しるべを示すことを目指す。
- ここでは**MS開発環境構築**([Part1[基本編]](Part1_基本編))、**製品(XLM)企画、要求分析、製品開発**([Part2[実装編]](#Part2_実装編))、**成果物の評価**([Part3[評価編]](#Part3_評価編))を順に追って教材を参考に進めていく。
- [Part2[実装編]](#Part2_実装編)以降は[Part1[基本編]](#Part1_基本編)、[業務プロセス](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)に則って**実務感覚**で実習する。<br><br>
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
- Application : [Reference](#Reference)

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
  - Hello RTOS
  - printf(SWO)
- [業務プロセス・組織](https://github.com/gtuja/CSC_MS/blob/main/Part1/3.ProcessAndOrganization.md)
  - 業務プロセス
  - 開発組織・役割・成果物

</details>

<div id="Part2_実装編"></div>
<details open>
<summary><font size="5"><b>Part2[実装編]</b></font></summary>

- [TOC](#toc)<br>
- XLM(X? Light Manager)
  - 製品要求
- 要求分析
  - システム要求仕様
  - ソフトウエア要求仕様
- ソフトウエアデザイン
  - HLD : パッケージ図
  - 時系列 : シーケンス図
  - 状態遷移 : ステートマシン図
- ソフトウエア開発
  - ソフトウエア構成
  - Interface / Data Structure
  - コーディング規則
  - Doxygen

</details>

<div id="Part3_評価編"></div>
<details open>
<summary><font size="5"><b>Part3[評価編]</b></font></summary>

- [TOC](#toc)<br>
- 評価業務プロセス
  - 単体試験
  - 結合試験
  - 妥当性評価

</details>

<div id="Reference"></div>
<details open>
<summary><font size="5"><b>Reference</b></font></summary>

- [TOC](#toc)<br>
[![GSL](https://img.shields.io/badge/GSL-Gtuja-baff13?style=plastic)](https://github.com/gtuja/Gsl)
[![Git](https://img.shields.io/badge/Git-baff13?style=plastic&logo=Git&logoColor=%23F05032&labelColor=white)](https://git-scm.com/)
[![TortoiseGit](https://img.shields.io/badge/TortoiseGit-baff13?style=plastic)](https://tortoisegit.org/)
[![Markdown](https://img.shields.io/badge/Markdown-baff13?style=plastic&logo=markdown&logoColor=%23000000&labelColor=white)](https://daringfireball.net/projects/markdown/)
[![Stm32 Cube](https://img.shields.io/badge/STM32Cube-baff13?style=plastic&logo=stmicroelectronics&logoColor=%2303234B&labelColor=white)](https://www.st.com/en/development-tools/stm32cubeide.html)
[![FreeRTOS](https://img.shields.io/badge/FreeRTOS-baff13?style=plastic&logoColor=%23)](https://www.freertos.org/)
[![draw.io](https://img.shields.io/badge/draw.io-baff13?style=plastic&logo=diagramsdotnet&logoColor=%23F08705&labelColor=white)](https://app.diagrams.net/)
[![doxygen](https://img.shields.io/badge/Doxygen-baff13?style=plastic)](https://www.doxygen.nl/)

</details>


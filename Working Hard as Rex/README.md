# Working Hard as Rex

- **難度**：High
- **時間限制**：1000 ms
- **記憶體限制**：256 MB
- **答對率 AC Rate**：0.92%
- **總提交次數 Total**：759 次

>## 描述

Rex 是一位 BIOS Developer，他桌面有很多個資料夾，資料夾編號從 0～N−1，裡面存放了要寄給老闆的更新內容。
Rex 工作時都會埋一些 bug 在資料夾裡面，這樣之後就可以解掉自己創造的 bug 假裝有在做事；
也會更新一些 BIOS 的新 feature（或是 Rex 堅持某些 bug 是 feature）。  
**假設在資料夾 i 內的 bug 數量＝Nbug，feature 數量＝Nfeature。其中 Nbug − Nfeature＝Ni。**  
Rex 有個習慣是會選擇連續的資料夾當做要寄給老闆的更新內容，但希望選取的範圍那幾個資料夾 **平均的 Ni** 要大於等於 Ａ，這樣 bug 夠多，可以下次解掉這些 bug 當作下次的進度報告；
但又怕太多 bug 會被老闆發現，所以平均的 Ni 數量不能大於 B。  
請算出 Rex 有幾種選擇，使他選到的資料夾連續且 A ≤ 平均 Ni ≤ B  
例如：  
N＝3，A＝3，B＝7，N₀＝1，N₁＝5，N₂＝15。  
表示 Rex 有 3 個資料夾，而且 3 個資料夾的 Ni 分別為 1 5 15，Rex 希望選到連續的資料夾而且平均的 Ni 滿足 3 ≤ 平均的 Ni ≤ 7  
則共有  
1. 選擇資料夾 1（平均 Ni＝5）
2. 選擇資料夾 0 1（平均 Ni＝(1＋5)/2＝3）
3. 選擇資料夾 0 1 2（平均 Ni＝(1＋5＋15)/3＝7）

共有 3 種可能使資料夾連續且平均 Ni 皆在範圍內，故答案為 3

>## 輸入

Each input set will contain two lines.  
The first line has 3 integers：N A B  
The second line has N numbers, in order from N₀ to Nₙ₋₁
- 1 ≤ N ≤ 10⁵
- −10⁹ ≤ A ≤ B ≤ 10⁹
- −10⁹ ≤ Ni ≤ 10⁹

>## 輸出
A number indicates how many selecting methods there are.

>## 輸入範例 1

    3 3 7
    1 5 15
>## 輸出範例 1

    3
>## 輸入範例 2

    2 -1 1
    -5 5
>## 輸出範例 2

    1

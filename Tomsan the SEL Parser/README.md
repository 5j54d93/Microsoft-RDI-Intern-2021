# Tomsan the SEL Parser
- **難度**：Low
- **時間限制**：1000 ms
- **記憶體限制**：256 MB
- **答對率 AC Rate**：24.06%
- **總提交次數 Total**：374 次
> ## 描述
Tomsan 每天在微軟的工作就是看 BMC 或是 BIOS 的 Sel（System Event Log），希望自己寫的 BIOS Code 如他預期的在 Server 上跑。
Sel 通常是以 16 進位的方式呈現，Tomsan 內力深厚，所以自己能夠在腦中翻譯成人類語言。
但是 Tomsan 最近的工作十分繁忙，有時候要上廁所，有時候要裝咖啡拿餅乾，有時候同事還會煩他。
而且 Tomsan 因為都坐在電腦前面一直看 Sel，進微軟之後越來越胖，好像胖到快要佔到隔壁同事的位置了。
請你幫幫可憐的 Tomsan，把 Sel 直接翻譯成人類語言，讓 Tomsan 的工作輕鬆一點！
Sel 的格式以 16 進位，11 byte 表示一筆 Sel 的編號、時間、BMC/BIOS Event、Event Success/Fail，11 個 byte 分別代表：

|Byte|Field|Description|
|:------|:------|:------|
|1:2|Record ID|表示這筆是第幾筆 Sel，以 Little-Endian 方式儲存。|
|3:8|Timestamp|這筆 Sel 印出來的時間<br>3:4：年份（Little-Endian）<br>5：月份<br>6：日<br>7：時<br>8：分|
|9:10|Generator|BIOS：d2 00 / BMC：e5 00|
|11|Event Status|Success：01 ／ Fail：02|

例如 01 00 e5 07 01 1c 07 2e e5 00 02 為一筆 Sel，其：
- 1:2（01 00）：表示編號，因為用 Little-Endian 儲存，所以是 0x0001，也就是 1
- 3:4（e5 07）：表示年，因為用 Little-Endian 儲存，所以是 0x07e5，也就是 2021
- 5（01）：月，1
- 6（1c）：日，28
- 7（07）：時，7
- 8（2e）：分，46
- 9:10：BMC 或是 BIOS
- 11：Success 或是 Fail

所以輸出是 Record 1: 2021/01/28 07:46 BMC Event Fail
> ## 輸入
題目的第一行數字是共有 n 筆 Sel，接下來的 n 行是請你們幫忙翻譯的 Sel。  
1 ≤ n ≤ 100  
不需處理任何 Overflow 問題，每個欄位都不會超過其儲存上限，或是出現不合理的日期。
> ## 輸出
請輸出翻譯過後的 Sel，格是為：  
Record {1}: {2}/{3}/{4} {5}:{6} {7} Event {8}  
- {1}：編號
- {2}：年
- {3}：月（要補滿兩位數，例如 7 月你應該輸出 07）
- {4}：日（要補滿兩位數）
- {5}：時（要補滿兩位數）
- {6}：分（要補滿兩位數）
- {7}：BIOS/BMC
- {8}：Success/Fail
> ## 輸入範例 1

    1
    01 00 e5 07 01 1c 07 2e e5 00 02
> ## 輸出範例 1

    Record 1: 2021/01/28 07:46 BMC Event Fail
> ## 輸入範例 2

    3
    01 00 e5 07 01 15 05 37 e5 00 01
    02 00 e5 07 01 18 05 3a e5 00 02
    03 00 e5 07 01 09 16 39 d2 00 02
> ## 輸出範例 2

    Record 1: 2021/01/21 05:55 BMC Event Success
    Record 2: 2021/01/24 05:58 BMC Event Fail
    Record 3: 2021/01/09 22:57 BIOS Event Fail
> ## 輸入範例 3

    5
    01 00 e5 07 01 17 05 2b e5 00 02
    02 00 e5 07 01 10 16 1e e5 00 01
    03 00 e5 07 01 15 0a 36 e5 00 01
    04 00 e5 07 01 10 10 14 d2 00 01
    05 00 e5 07 01 08 06 00 d2 00 01
> ## 輸出範例 3

    Record 1: 2021/01/23 05:43 BMC Event Fail
    Record 2: 2021/01/16 22:30 BMC Event Success
    Record 3: 2021/01/21 10:54 BMC Event Success
    Record 4: 2021/01/16 16:20 BIOS Event Success
    Record 5: 2021/01/08 06:00 BIOS Event Success

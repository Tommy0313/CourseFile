# Homework 00

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫：

⚠️ Due: 2024/09/18 11:59 p.m. ⚠️

## 說明

### 目標

- [ ] 了解並使用 Git
- [ ] 使用 Jenkins 與 Gitea 介面
- [ ] 觀察 CMake 編譯及運行當前專案

### 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```txt
./
├── CMakeLists.txt
├── .clang-format
├── README.md
├── LICENSE
├── .gitignore
├── cmake
│    └── Dependencies.cmake
├── files.cmake
├── include
│    └── hello_OOP.hpp
├── src
│    └── hello_OOP.cpp
└── test
     ├── ut.sanity_check.cpp
     └── ut_hello_OOP.cpp
```

## 題目評分

- ［100 分］取得兩個綠勾勾
  - 若在功課截止時依然沒有取得兩個綠勾勾，判定本次功課為 0 分。

## 注意事項

- 你不應該上傳 `/bin` 資料夾至專案上。
  - 你的功課不應該出現 Memory Leak，否則將會扣作業總分 10 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 資料夾存在在專案庫中，扣除作業總分 5 分。

## 敘述

> 嗨，歡迎參加 OOP 課程。
>
> 想必你已經完成了第一週的課程，並已經瞭解這一門課環境相關的設施（若還不了解的話，可以看一下第一週第一堂的簡報）
>
> 在這個任務中，你會了解如何透過命令的方式操作 Git 工具，期望你可以在這一個功課上更佳瞭解作業相關的環境，GL & HF！

Uriah 是 OOP 的一位學生，接下來他將會帶著你一起完成這份作業。

請嘗試完成任務，並在 Jenkins 上拿到綠色的 Correct 勾勾。

## 題目敘述

在這個任務中，你會擁有一個你自己的功課版本庫（Repository），他會叫做 `OOP2024f_<學號>_HW`，接著你就能根據以下的任務開始逐一完成。

### 任務一、利用 `git clone` 下載 TA Team 的作業版本庫

首先，我們要先將 Gitea 上的遠端版本庫下載至我們的本地端，他就像是從 Gitea 下載檔案下來一樣，我們可以使用 `git clone` 來下載專案。

在這之前，我們先來使用 `git clone` 將作業下載至本地端吧！透過以下的指令來將作業下載至本地端。

```bash=
git clone git@gitea.is1ab.com:TAT/OOP2024f_hw.git
```

透過這個指令後，你就能夠將遠端專案庫下載至本地端，並且它已經預先幫你設置好了遠端版本庫為 `https://gitea.is1ab.com/TAT/OOP2024f_hw.git`。

當你使用 `git push` 時，他會將變更推送至遠端版本庫上。

### 任務二、利用 `git clone` 下載個人的作業版本庫

接下來，我們會需要將 TA Team 的作業專案移至個人的作業專案上，所以我們再透過 `git clone` 將個人作業的版本庫下載下來，使用 SSH 連結。

```
git clone git@gitea.is1ab.com:109590031/oop2024f_109590031_hw.git
```

接著你就能夠從 `OOP2024f_hw` 將作業檔案移至自己本地的作業版本庫中。

＊請注意：當你 Clone 你自己的版本庫時，你應該要使用 SSH 而非 HTTPS，他的連結會長得像是這樣：`git@gitea.is1ab.com:TAT/OOP2024f_hw.git`，這樣你才會有權限能夠推送變更至目標版本庫。

### 任務三、在本地上編譯運行專案

接下來的作業（Homework 00 至 Homework 07）將會透顧 `CMake` 進行建構與運行。

CMake 是一個建構工具，透過該建構工具，我們可以較輕鬆的編譯原始碼，變成可執行檔。

在這個任務中，你將需要透過 CMake 編譯作業檔案，並確保他能夠正確地被編譯與執行。

對於作業相關的環境設置，請參考 [Environment Setup](https://hackmd.io/@OOP2023f/rk2-8cVCh)。

### 任務四、推送分支

當你確認完成，專案都已實作完畢。設定也都完成時，就可以推送變更到遠端的 Git 倉庫中了。

接下來你需要把此項專案重新上傳的自己的專案庫上面。之後就會觸發 Jenkins 的檢查。

注意！ 你上傳的文件為這份專案，而非自己寫一個`main.cpp` 上傳上去。

```
git remote set-url origin git@gitea.is1ab.com:<學號>/OOP2024f_<學號>_HW.git
```

```

git add .

```

```

git commit -m "Add homework files"

```

```bash
git push origin main
```

### 任務五、查看 Gitea 上專案是否已變更

當你推送完成後，請確認自己在 Gitea 的遠端版本庫是否已有作業的檔案，若先前的步驟推送成功後，他將觸發 Jenkins 來進行測試。

### 任務六、觀察 Jenkins 上的綠勾勾

進入 [Jenkins](https://jenkins.is1ab.com)，在 Jenkins 上，你將有兩個 Job，一個是 `OOP2024f_<學號>_HW`，另一個則是 `OOP2024f_<學號>_TA`。

在 Jenkins 上，如果要拿到 HW 專案的綠勾勾，則需要做到：

1. 通過自己寫的測試
2. 專案上沒有 Memory Leak 的問題
3. 專案上的 Test Coverage 大於 95%

Jenkins 會自動逐步幫你確認，若滿足了以上三項，則會給你一個綠色的勾勾。

當拿到 HW 專案的綠勾勾時，他將觸發 TA 專案，進行額外的評測：

1. 通過所有助教寫的測試。
2. 在使用助教寫的測試時，專案不會出現 Memory Leak 的問題。

當你也通過以上兩點後，恭喜你，你就能拿到兩個綠色勾勾了。

## Homework's meme

![1725801808581](./docs/image.png)

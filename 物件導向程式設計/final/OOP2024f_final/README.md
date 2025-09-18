# Final：A Bank
## Description
> [!NOTE]
> 您好，我叫 `Kesshoban3310` ，我並沒有建立銀行系統的經驗，
> 現在還差一個工程師就可以滿足我的需求，你現在幫過我，
> 我承諾你會破台這份期末，並且成為銀行大股東，謝謝！


>  [!NOTE]
> 在5202年的時空，各國雖然仍然有各自的貨幣，但在貿易以及溝通時，
> 會使用一種叫做Okapi Oriented Penny，簡稱OOP的世界幣做轉換，
> 以下的表格會給你各國貨幣與OOP幣之間的關係。

| 幣種 | 每一元貨幣可兌換多少 `OOP` 幣 |
| -------- |--------------------|
| `PUA`     | 6                  |
| `TWP`     | 8                  |
| `OOTD`     | 4                  |
| `FS`     | 2                  |

> [!TIP]
> 5202年的各國發展已於現今有很大的差別，故貨幣代碼非現今各國貨幣代碼。
> 兌換方式為，如果我今天想要將 `100` 元 `TWP` 換成 `OOTD` ，那我可以將 `100` 元 `TWP` 換成 `800` 元 `OOP` ，再轉成 `200` 元`OOTD` 。
> 各國之間的貨幣不會有小數點以下的幣值，包含 `OOP` ，所以兌換時以無條件捨去法進行兌換，關於無條件捨去，可以使用 `std::floor` ，參考資料在下方的 `Notion` 。
> 你不需要假設各國銀行的幣值，隨意設計即可。

### Task 通則

- 請完善每個物件的建構子。
- 初始檔案需要先將每個類別關係做繼承以及完善建構子後，才可以使該 `Task` 編譯成功。
- 在 `Score` 區，會告訴各個 `Task` 所執行的檔案。
- 保證時間的格式為 `YYYY-MM-DD` ，例如你看到這份考題的當下應該是 `2025-01-10` 。
### Task1 完成紙幣物件

- 首先請觀察`Money.hpp` ，在裡面有 `enum class MoneyType` ，代表紙幣的種類，你需要設置好完美的 `Getter` 跟 `setter`。
    - 對於 `int GetAmount` ，請回傳紙幣的 `amount` 。
    - 對於 `MoneyType GetType` ， 請回傳紙幣的 `type` 。
    - 對於建構子，你應該要設置好紙幣的 `Type` 以及 `Amount` 。
### Task2 完成帳戶物件

- 首先觀察 `Account.hpp` ，內部有建構子以及各個函數。
    - `AccountType GetAccountInfo()` 回傳 `Account` 的類別。
    - `std::string GetUser()` 回傳 `Account` 的 `User` ，也就是所有者。
    - `int GetTotal()` 回傳這個帳戶的總額。
    - `virtual void Modify(Operation oper,MoneyType type,int amount) = 0` 根據銀行的操作進行帳戶的調整。
        - `Operation::Deposit` ，代表存入。
        - `Operation::Withdraw` ，代表提領。
        - 為純虛擬函數，需要在子類別中被相同的函數覆寫，請先判斷 `oper` 的狀態後再進行存入或提領的撰寫 。
- `PersonalAccount.hpp` 是 `Account.hpp` 的子類別。
    - `PersonalAccount.hpp` 內有一個成員為 `MoneyType type` ，代表該帳戶儲存的幣種。
    - `MoneyType GetMoneyInfo()` 回傳這個帳戶的可儲存的幣種。
    - `void Modify(Operation oper,MoneyType type,int amount)` 對於這個函數。
        - 無論任何操作，如果函數的 `MoneyType type` 與這個帳戶的 `type` 不同，你應該要拋出 `std::invalid_argument` 。
        - 在提領操作下，若 `int amount` 的數字超過 `PersonalAccount` 的 `money` ，拋出`std::out_of_range`。
- `BusinessAccount.hpp` 也是 `Account.hpp` 的子類別。
    - `BusinessAccount.hpp` 可以存入所有幣種的金額，存入時轉換成 `OOP` 幣。
    - `void Modify(Operation oper,MoneyType type,int amount)` 根據銀行的操作進行帳戶的調整。
        - 對於存入， `type` 為目標幣種， `amount` 為幣值。
        - 對於提領， `type` 為目標幣種， `amount` 為幣值。
        - 在提領操作下，若 `int amount` 的數字超過 `BusinessAccount` 的 `money`，拋出`std::out_of_range`。


### Task3 完成Ticket物件
#### Task3-1 觀察Ticket介面及物件
- 以下函數皆在 `Ticket.hpp` 裡面。
- `Ticket` 提供不同的票據父類別，以下該物件有的函數。
    - `Info GetTicketInfo` 取得票據的資訊，應該要是純虛擬函數。
- `ITimely` 代表該票據有時間期限。
    - `std::string GetTime` 代表回傳票據的時間。
- `enum class TicketType` 表示票據種類。
    - 分別有 `Cheque` 、 `Deposit` 、 `Loan` 。
- `struct Info` 有多種函數成員，其中：
    - `MoneyType type` 代表支付方所訂定的金幣種類。
    - `int amount` 該張票據的金額。
    - `double rate` 該張票據的利率 (選填)。
    - `std::string drawer` 代表支付方。
    - `std::string payee` 代表兌換方。
    - `TicketType tickettype` 該張票據的種類。
- 以上物件皆被包覆在 `namespace Ticket` 內。
#### Task3-2 製作Ticket物件
- 接下來你會實作三種不同票據 `Cheque` 、 `Deposits` 、 `Loan`  。
    - 請你實作好這些票據的建構子。
    - 只需要完善函數功能即可。
- 分別在以該名字為命名的 `.hpp` 內，這裡會告訴你各個票據用途。
    - `Cheque`
        - `Cheque` 為一種雙方約定好的票據，兌換者可以隨時兌換。
        - 測資會保證支付方金額足夠扣款。
    - `Deposits`
        - `Deposits` 為使用者與銀行約定的票據，兌換者在到期日之後可以兌換，並且獲得票據的金額，票據內應該要設有利率，兌換者獲得的金額是 `原金額*利率`，計算後數字無條件捨去至整數位。
    - `Loan`
        - `Loan` 為使用者與銀行約定的票據，使用者需要在到期日前進行兌換，使用後會從支付者(使用者)帳戶扣除`原金額*利率`，計算後數字無條件捨去至整數位。
        - 在 `Loan` 產生時，請增加使用者帳戶同樣一筆金額。
> [!TIP]
> - 你可以根據以上四種物件的建構子的物件去推敲所需要的變數。
> - 票據只提供交易雙方訊息， `Task3` 只負責造出 `Ticket` 物件，實際兌換後操作請在 `Task4` 完成。
> - `Deposit` 以及 `Loan` 的 `MoneyType type` 是使用者的 `type` ， `Cheque` 以 `drawer` 為主。
            
### Task4 完成銀行系統

- 透過以上三個任務，你現在可以來完成一個銀行系統了，現在請查看 `Bank.hpp`！
- 這裡假設 `kesshoban3310` 的爺爺給他一座金山，導致他不用考慮銀行的錢會不會被全部提領光光。
    - `void SetAccounts(std::vector<std::shared_ptr<Account> > accounts)` 會將銀行的帳戶進行設定。
    - `int QueryAccount(std::string id)` 根據 `id` 尋找帳戶，回傳該帳戶的 `index` ，若沒有該帳戶，回傳 `std::invalid_argument` 。
    - `void Deposit(std::vector<Money> moneys,std::string id)` 根據 `moneys` 計算存入總額並且根據 `std::string id` 找尋對應的帳戶進行存款。
        - 若沒有該帳戶，回傳 `std::invalid_argument` 。
    - `std::vector<Money> Withdraw(Money money, std::string id)` 根據傳入的 `money`，並根據 `id` 找尋帳戶後，提領出相對應的金錢出來。
        - 接受回傳的 `std::vector<Money>` 多種組合解，只要 `std::vector<Money>` 內的 `money` 總和對即可。
        - 如果帳戶內金錢少於 `money` 內的 `amount` ，拋出 `std::out_of_range` 。
        - 若沒有該帳戶，回傳 `std::invalid_argument` 。
    - `std::vector<Money> Exchange(std::vector<Money> money,MoneyType exchangetype)` ， `money` 為交換傳入的 `money` ， 請根據 `exchangetype` 轉成對應的幣種後回傳。
        - 保證傳入的 `std::vector<Money> money` 的每個 `MoneyType` 會一樣。
    - `std::shared_ptr<Ticket::Ticket> MakeTicket(Ticket::TicketType type,std::string drawer,std::string payee,MoneyType moneytype,int amount,std::string time)` 為建立一張 `Ticket`。
        - 若牽涉到利率相關票據，利率為 `0.03` ，其他票據則為 `0.0` 。
        - 支付者為 `drawer` ， 兌換者為 `payee` 。
    - `void UpdateTime(std::string time)` 更新時間為 `time` 。
        - 若更新時間較舊則不要更新。
    - `std::string GetTime()` 取得 `time` 。
    - `void ExchangeTicket(std::shared_ptr<Ticket::Ticket> ticket)` 為票據兌換。
        -  已經將各個部分所需要降轉的物件處理好，直接調用降轉後類別的 `function` 即可。
            - 在 `case Ticket::TicketType::Cheque` 內 `payee` 為 `TicketType::Cheque` 。
            - 在 `case Ticket::TicketType::Loan` 內 `loan` 為 `Ticket::Loan` 。
            - 在 `case Ticket::TicketType::Deposits` 內 `deposits` 為 `Ticket::Deposits` 。
        -  在兌換時，如果票據的金錢種類與兌換者的金錢種類不符，請轉成與兌換者同等值的幣值，並且將轉換後金額 `*0.98` 。
        -  若 `Deposits` 在未到期時進行兌換，拋出 `std::invalid_argument` 。
        -  若 `Loan` 在到期日後兌換，則將金額再乘上 `1.05` 進行懲罰。
        - 對於 `Deposits` ，你不用查找 `drawer` 的帳戶。
        - 對於 `Loan` ，你不用查找 `payee` 的帳戶。
    - `std::vector<Money> Calculator(int amount,MoneyType type)` 根據傳入的 `type` 以及 `amount` 生成一個為 `money` 的陣列，陣列內 `money` 的總額相加後應該要跟 `amount` 一樣。
        - 接受多種組合解，只要總和對即可。
        - 這個函數是為了方便你們在 `Withdraw` 以及 `Exchange` 的時候不用寫重覆的程式碼使用，可以在寫完後使用在裡面。
## Score

- [15%] Task1
    - `ut_money.cpp` (ut_test_1)
- [15%] Task2
    - `ut_account.cpp` (ut_test_2)
- [20%] Task3
    - `ut_ticket.cpp` (ut_test_3)
- [50%] Task4
    - [15%] `ut_bank_easy.cpp` (ut_test_4)
    - [35%] `ut_bank_diff.cpp` (ut_all)
## Notion

- 關於時間比較，你可以直接用字典序判斷。

```c++
#include <string>
#include <iostream>
int main(){
    std::string s1 = "2024-12-22";
    std::string s2 = "2025-01-10";
    s1 < s2; //true
    s1 > s2; //false
}
```

- 關於無條件捨去，你可以使用 `std::floor()` ，參考資料在[這篇](https://en.cppreference.com/w/cpp/numeric/math/floor)。
```c++
#include <string>
#include <iostream>
#include <cmath>
int main(){
    std::cout << std::fixed
              << "floor(+2.7) = " << std::floor(+2.7) << '\n'; //output = 2.7
}
```

- 關於本次 `task` ，你可以切換做測試 (以 `Clion` 為例)。  
![image](https://hackmd.io/_uploads/rJPa_eFIke.png)
- 關於本次 `task` ，你可以切換做測試 (以 `VSC` 為例)。  
![vsc](https://hackmd.io/_uploads/rkYwfOa8ke.png)

# Meme

![finalmeme](https://hackmd.io/_uploads/HkvBwP6Ukg.png)



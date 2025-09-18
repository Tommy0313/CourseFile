# Homework 03

> 這份作業由物件導向程式設計助教群所製。
> 如有問題，歡迎使用以下方式聯繫助教：

>> Email: t111590004@ntut.org.tw
>> MS Teams: 張意昌
⚠️ Due: 2024/11/13 11:59 p.m.  ⚠️



## 說明

### 目標

- [ ] 學會繼承以及其使用。
- [ ] 學會純虛擬函數。
- [ ] 學會 `std::share_ptr` 的應用。

### 檔案架構

請確認提交是否符合以下的檔案架構，否則無法進行評分。

```txt=
./
├── CMakeLists.txt
├── LICENSE
├── README.md
├── .gitignore
├── .clang-format
├── files.cmake
├── include
│   └── Drink.hpp
│   └── Food.hpp
│   └── Ingredients.hpp
│   └── MainDish.hpp
│   └── OishiiPapa.hpp
│   └── Order.hpp
│   └── Package.hpp
│   └── SideDish.hpp
├── scripts
│   ├── CodeCoverage.cmake
│   └── coverage.sh
├── src
│   └── Drink.cpp
│   └── Food.cpp
│   └── MainDish.cpp
│   └── OishiiPapa.cpp
│   └── Order.cpp
│   └── Package.cpp
│   └── SideDish.cpp
└── test
    └── ut_Food.cpp
    └── ut_Oishiipapa.cpp
    └── ut_Package.cpp
```



## 題目評分

- ［80%］完成第一部分。
  - `MAINDISH_TEST` 20%
  - `SIDEDISH_TEST` 20%
  - `DRINK_TEST` 10%
  - `PACKAGE_TEST` 30%
- ［20%］完成第二部分。
  - `OISHIIPAPA_TEST` 20%
- 依照完成部分比例給分，取上傳紀錄中最高者記錄之。
## 注意事項

- 你不應該上傳 `/bin` 資料夾至專案上。
  - 你的功課不應該出現 Memory Leak，否則將會扣作業總分 10 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 資料夾存在在專案庫中，扣除作業總分 5 分。

## 敘述

> 嗨，歡迎參加 OOP 課程。
>
> 想必你已經完成了 Lecture 03 的課程，並瞭解有關於繼承的觀念。
> （若還不了解的話，可以查看 Lecture 03 的簡報）
>
> 在這個任務中，你會了解如何使用課堂上所描述的繼承觀念。

請嘗試完成任務，並在 Jenkins 上拿到綠色的 Correct 勾勾。

## 題目敘述

> 在這份任務中，我們嘗試設計出速食店的餐點。

`Original Oishii Papa` 是一間在世界各地有許多分店的美味速食店，`kesshoban` 想要在北科的藍光園地內開設一間分店，現在請你幫他完成一個簡單的管理系統。

由於 `Original Oishii Papa` 的核心精神是以簡單、美味為主，所以店內只有簡單的漢堡與美食組合，以下是他的餐點：


| 品名 |英文品名| 食材 | 價格 |
| -------- |-----| -------- | -------- |
| 豬肉堡     |PorkBurger| 一份豬排、一份生菜、一份漢堡麵包、一份起司     | 59     |
| 牛肉堡     |BeefBurger| 一份牛排、一份生菜、一份漢堡麵包、一份起司     | 69     |
| 魚排堡     |FishBurger| 一份魚排、一份生菜、一份漢堡麵包、一份起司     | 79     |

* 以上主餐 `maindish` 會存在 `Ingredients.hpp` 的 `enum class Production` 裡。

當然，主餐也可以增加一些不同的配料，以下是可以增加的配料

| 品名 |英文品名| 價格 |
| -------- |-----| -------- |
| 豬肉     |PorkSteak| 20     |
| 牛肉     |BeefSteak| 20     |
| 魚排     |FishSteak| 20     |
| 生菜     |Lattuce  | 10     |
| 起司     |Cheese   | 10     |

* 以上配料會存在 `Ingredients.hpp` 的 `enum class Ingredients` 裡，請參考食材名稱區。


| 品名 |英文品名| 食材 | 備註 |
| -------- |-----| -------- | -------- |
| 薯條     |Frenchfries| 一份薯條     | 小份44 <br> 大份59     |
| 雞塊     |Nugget| 一份雞塊     | 小份44 <br> 大份59     |
| 沙拉     |Salad| 一份沙拉     |  59    |

* 以上附餐 `sidedish` 會存在 `Ingredients.hpp` 的 `enum class Production` 裡。


| 品名 |英文品名| 食材 | 備註 |
| -------- |-----| -------- | -------- |
| 可樂     |Cola| 一份可樂     |  中杯28 <br> 大杯38    |
| 雪碧     |Spirit|一份雪碧     | 中杯28 <br> 大杯38     |
| 焦糖奶茶   |CaramelMilktea|一份奶茶、一份焦糖   | 中杯44     |
| 咖啡拿鐵   |Latte |一份咖啡、一份牛奶   | 中杯45 <br> 大杯55    |

* 中杯的 `ml` 是 `550` ， 大杯的 `ml` 是 `750` 。
* 以上飲料 `drink` 會存在 `Ingredients.hpp` 的 `enum class Production` 裡。

以上是整間速食店的餐點，接下來會給予相對應的食材。


| 食材中文 | 食材英文 |
| -------- | -------- |
| 豬排     | PorkSteak     |
| 牛排     | BeefSteak    |
| 魚排     | FishSteak     |
| 漢堡麵包  | BurgerBread     |
| 生菜     | Lattuce     |
| 起司     | Cheese     |
| 薯條     | FranchFries     |
| 雞塊     | ChickenNugget     |
| 沙拉     | Salad     |
| 可樂     | Cola     |
| 雪碧     | Spirit     |
| 奶茶  | Milktea     |
| 焦糖  | Caramel     |
| 咖啡  | Coffee    |
| 牛奶  | Milk |

* 以上食材會存在 `Ingredients.hpp` 的 `enum class Ingredients` 裡。

* 在 `Ingreditents.hpp` 內，所有的東西都會用英文呈現，例如：豬排堡是 `Production::PorkBurger` 。

### 任務一、在基礎類別中完成getter與setter

- 在本次任務中，有一個基礎類別，也就是 `Food.hpp`。
- 請於 `Food(Production id)` 內完成建構子。
- 請於 `void getid()` 這個 `function` 內，回傳 `Production id` 這個物件。
- 請於 `std::vector<Ingredients> GetIngredient()` 這個 `function` 內，回傳 `std::vector<Ingredients> ingredient` 這個物件。
- 請設置 `void MakeFood()` 為一個純虛擬函數。
- 請於 `int GetMoney()` 內 ，回傳 `int money` 這個物件。

### 任務二、在衍伸類別中完成物件

- 接下來會有三個 `class`，分別為 `maindish.hpp` 、 `sidedish.hpp` 、 `drink.hpp` ，這三個物件皆為 `food.hpp` 的衍伸物件，請根據對應的任務完成相對應的內容。

- 共通部分
  - 對於 `money` 這個物件，你應該要在 `void MakeFood()` 內進行修改。
  - 對於三個 `maindish` 、 `sidedish` 、 `drink` ， 你應該完成相對應的建構子。 
  - 你應該在合適的地方呼叫 `void MakeFood()` 。


- `maindish.hpp`
  - 對於 `void AddIngredients(std::vector<Ingredients> addtional)` 加入 `std::vector<Ingredients> addtional` ，並且重新計算價格。
    - 若 `addtional` 內有任一一項食材未出現在 `額外配料Addtional` 的表格內，請拋出 `std::invalid_argument` 。
- `sidedish.hpp`
  - 除了 `沙拉` 以外的物件，如果 `void MakeLarger()` 被呼叫，你就要將 `SideDishType type` 設定成 `SideDishType::BIG` ，並且重新計算價格。
  - 對於 `SideDishType GetType()` ，你應該回傳 `SideDishType type` 。
- `drink.hpp`
  - 除了 `焦糖奶茶` 以外的物件，如果 `void makelarger()` 被呼叫，你要將 `ml` 設定成 `750` ，並且重新計算價格。
  - 根據 `int GetMl()` ，你應該要回傳 `ml` 。

- 有以下一個部分請你要注意
  - 在設計 `void MakeFood()` 時，請依照表格給的順序做填充，例如：豬排堡，那麼順序就是 `豬肉排、生菜、漢堡麵包、起司` 。

### 任務三、完成包裝的物件

- 接下來有一個叫做 `Package.hpp` 的檔案，是製作一份完整的餐點。
- 對於 `void SetMainDish(MainDish maindish)` 你應該要將 `maindish` 設置在 `std::shared_ptr<MainDish> maindish` 內。
- 對於 `void SetSideDish(SideDish sidedish)` 你應該要將 `sidedish` 設置在 `std::shared_ptr<SideDish> sidedish` 內。
- 對於 `void SetDrink(Drink drink)` 你應該要將 `drink` 設置在 `std::shared_ptr<Drink> drink` 內。
- 對於 `void CountMoney()` 你應該要計算當前這份 `Package` 內的餐點總價是多少後設定在 `money` 裡面，計算規則可以參考表格，並且當 `maindish` 、 `sidedish` 及 `drink` 都有東西時，請將 `money` 減少 `15`。


## 題目敘述 (Part 2)

接下來這個部分將會實作一個簡易的速食店系統，請根據對應的任務完成相對應的功能。

速食店的 `class` 為 `OishiiPapa.hpp` 。

### 任務一、觀察訂單物件

- 接下來請觀察 `Order.hpp` 這個物件，將會告訴你訂單的應用。
  - `std::vector<Production> product` 內存放該筆訂單所需求的產品，我們保證順序一定是 `{主餐,附餐,飲料}` 。
    - Ex: `std::vector<Production> product = {PorkBurger,_NULL,Cola}` ， 代表只需要 `豬排堡` 以及 `可樂` 。
  - `std::vector<Ingredients> addtional` 內代表 `主餐` 所需要的加料。
  - `std::vector<bool> larger` 代表 `附餐` 及 `飲料` 是否需要加大，我們保證順序一定是 `{附餐,飲料}` 。
    - Ex: `std::vector<bool> larger = {false,true}` ，代表附餐不用加大但飲料一定要。
    - 保證沒有出現的餐點的那欄一定是 `false` 。
  - 根據 `std::vector<Production> GetProductInfo()` ，你應該回傳 `std::vector<Production> product` 。
  - 根據 `std::vector<Ingredients> GetAddtionalInfo()` ， 你應該回傳 `std::vector<Ingredients> addtional` 。
  - 根據 `std::vector<bool> GetLargerInfo` ，你應該回傳 `std::vector<bool> larger` 。
### 任務二、根據接收到的訂單製作物件
- 對於 `void SendOrder(Order order)` ，你應該將 `order` 傳入 `std::queue<Order> pipeline` 內。
- 對於 `void MakeDish()` ，請根據物件 `std::queue<Order> pipeline` 內最上方的 `Order` 回傳，進行相對應的 `Package` 製作，並且將製作好的物件放入 `std::queue<Package> chest` 內。
  - 若當前的 `chest` 大小至少 `15` ，則不要製作餐點。
  - 若當前的 `std::queue<Order> pipeline` 為空，則拋出 `std::out_of_range()` 。
### 任務三、進行餐點管理
- 對於 `Package Pickup()` 這個function，請觀察 `std::queue<Package> chest` 這個物件，當 function 被呼叫時，你應該將最上面的 `Package` 回傳，並且對 `Oishiipapa` 的 `money` 增加最上面的 `Package` 的 `money`，如果 `chest` 大小小於 `15` 且 `std::queue<Order> pipeline` 不為空，將 `std::queue<Order> pipeline` 內最上方的 `Order` 丟出來並製作餐點。
  - 若當前的 `std::queue<Package> chest` 為空，則拋出 `std::out_of_range()` 。
- 對於 `int GetMoney()` ，請回傳 `money` 。
- 對於 `Order GetOrderInfo()` ，請回傳 `std::queue<Order> pipeline` 最上層的 `Order` 。
### 任務提示
- 提示：你應該先取的 `chest` 最上方的 `Package` ，之後再判斷是否要製作新的餐點，然後回傳 `Package` 。
- `std::queue<Package> chest` 以及 `std::queue<Order> pipeline` 為 `queue` 這個資料結構，你應該去了解這個資料結構的用途，你可以參考[這篇](https://hackmd.io/@Ben1102/S1zcfIqnu)的介紹，用法會放在任務附註。

## 任務附註

- 你只需要實作任務所描述的function。
- 關於 `std::invalid_argument` ，你可以參考[這篇](https://en.cppreference.com/w/cpp/error/invalid_argument)。
- `std::invalid_argument`內可以寫任意東西。
- 關於 `std::out_of_range` ，你可以參考[這篇](https://en.cppreference.com/w/cpp/error/out_of_range)。
- `std::out_of_range`內可以寫任意東西。
- 關於 `std::queue` ，你可以參考[這篇](https://en.cppreference.com/w/cpp/container/queue)。
- 關於 `std::shared_ptr` ，你可以參考[這篇](https://en.cppreference.com/w/cpp/memory/shared_ptr)。

## Homework's meme


![meme](https://hackmd.io/_uploads/S1UnbyLbkg.png)

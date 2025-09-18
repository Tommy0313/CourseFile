# Midterm

## 說明

> 這次你是一個運通交通大亨，需要規劃、建造、管理你手底下的所有載具。

這次任務包含設計、製造和使用。在設計的部分，有一個基礎類別 `Vehicle` ，裡面包含這載具的各式各樣成員資訊，也有虛擬函數。`Bus`, `Plane`, `Boat`, `Train` 是繼承於 `Vehicle` 的子類別。他們四個當中也會有自己的私有成員以及需要重寫函數（override）。

在製造的部分，會有分散在美國與日本的兩個工廠，當中製造著設計完成的四個載具。雖然製造他們的函數名稱一樣，但你需要想辦法去限制他。

在使用的部分你需要製作維修站、加電油站以及售票站，你會需要注意是否載具的座位容量已達上限，或者加電油站的整體油量或者電量是否歸零。

### 任務零、前置說明

- 準則一：在實作建構子或者方法/函式的時候，當整數型別參數傳入時，必須檢查小於 `0` 則 `std::invalid_argument`。

- 表格一：所有載具所消耗的燃油類型。

  | 載具種類（`VehicleType`）- `Enum class` | 燃油類型（`FuelType`）- `Enum class` |
  | --------------------------------------- | ------------------------------------ |
  | `Train`                                 | `Electricity`                        |
  | `Plane`                                 | `Gasoline `                          |
  | `Bus`                                   | `Gasoline `                          |
  | `Boat`                                  | `Gasoline `                          |

- 表格二：所有載具生產國家的耐久值消耗程度。

  | 載具生產國家 - `String` | 載具種類 - `Enum class` | 消耗值 - `int` |
  | ----------------------- | :---------------------- | -------------- |
  | USA                     | Train                   | -4             |
  | USA                     | Plane                   | -30            |
  | USA                     | Bus                     | -5             |
  | USA                     | Boat                    | -4             |
  | Japan                   | Train                   | -5             |
  | Japan                   | Plane                   | -2             |
  | Japan                   | Bus                     | -1             |
  | Japan                   | Boat                    | -5             |
  | Other                   | Train                   | -10            |
  | Other                   | Plain                   | -10            |
  | Other                   | Bus                     | -10            |
  | Other                   | Boat                    | -10            |

- 表格三：所有載具在生產國家的對應標示。以下是建構子的所有按照順序的參數。

  | 載具生產國家 | 載具種類 | 國家 - `String` | 工廠 - `String` | 當前耐久值 - `int` | 載具種類 - `Enum class` | 參數五 - `int` | 參數六 - `int` |
  | ------------ | :------- | --------------- | --------------- | :----------------- | :---------------------: | -------------- | -------------- |
  | Japan        | Train    | `Japan`         | `Toyota`        | `0`                |  `VehicleType::TRAIN`   | `6`            | `12`           |
  | Japan        | Plane    | `Japan`         | `Mitsubishi`    | `0`                |  `VehicleType::PLANE`   | `0`            | `12000`        |
  | Japan        | Bus      | `Japan`         | `Yamaha`        | `0`                |   `VehicleType::BUS`    | `12`           | `80`           |
  | Japan        | Boat     | `Japan`         | `Shinkansen`    | `0`                |   `VehicleType::BOAT`   | `30`           | 無             |
  | USA          | Train    | `USA`           | `Amtrak`        | `0`                |  `VehicleType::TRAIN`   | `6`            | `12`           |
  | USA          | Plane    | `USA`           | `Boeing`        | `0`                |  `VehicleType::PLANE`   | `0`            | `12000`        |
  | USA          | Bus      | `USA`           | `Ford`          | `0`                |   `VehicleType::BUS`    | `12`           | `80`           |
  | USA          | Boat     | `USA`           | `Bayliner`      | `0`                |   `VehicleType::BOAT`   | `30`           | 無             |

  - 說明：參數五、六，**均由每種載具**的私有屬性而定。如火車的參數五表示火車車廂的節數，飛機的參數五表示飛機當前的高度。以此類推......。

- 表格四：票據種類

  | 參數一     | 參數二   | 參數三   | 參數四   | 參數五   | 參數六   |
  | ---------- | -------- | -------- | -------- | -------- | -------- |
  | 購買者名稱 | 單位價錢 | 票據編號 | 起始站點 | 終始站點 | 載具資訊 |

  - 價錢：`單位價錢 * 距離 * 優惠價（兒童 0.6 / 成人 1.0 / 老人 0.8 ）`
  - 票據編號：從 `0` 開始計算。

- 表格五：單位價錢

  | 載具種類 | 單位價錢 |
  | -------- | :------- |
  | Train    | 80       |
  | Plane    | 120      |
  | Bus      | 100      |
  | Boat     | 50       |

- 表格六：載具所能容納的空間

  | 載具種類 | 載具空間 |
  | :------- | :------- |
  | Train    | 1000     |
  | Plane    | 200      |
  | Bus      | 20       |
  | Boat     | 50       |

### 任務一、規劃所有載具 - 50%

- 類別： `Vehicle`：

  - 建構子：`Vehicle(std::string country, std::string model, int durability, VehicleType type)`。初始化成員，並檢查整數類型的成員範圍若小於零，請丟出 `std::invalid_argument`。
  - 方法：`bool IsDurabilityZero()`。是否載具耐久值為零
  - 方法：`void AddDurability(int value)`。增加載具的耐久值，且耐久值的最大值為 `100`，如果超過就 `std::invalid_argument`。
  - 方法：`int GetDurability()`。取得載具耐久值的 Getter。
  - 方法： `void AddEnergy(int value)`。增加載具的能量值，且能量值的最大值為 `1000`，如果超過就 `std::invalid_argument`。
  - 方法：`int GetEnergy()`。取得載具的能量值。
  - 方法：`std::string GetCountry()`。取得載具的製造國家。
  - 方法：`std::string GetModel()`。取得載具的生產工廠。
  - 方法：`virtual FuelType GetFuelType() = 0;`。顯示燃油種類，具體查看表格一。
  - 方法：`virtual void ConsumeDurability() = 0`。消耗耐久值，具體預設減少的值請查看表格二。

- 建構類別： `Train`，繼承 `Vehicle` 類別。
  - 建構子： `Train(std::string country, std::string model, int durability, VehicleType type, int carriage, int maxCarriage)`。初始化成員，並檢查整數類型的成員範圍若小於零，請丟出 `invalid_argument`。如果當前節數超過最大的車廂節數，就 `std::invalid_argument`。
  - 方法： `void SetCarriage(int value)`。設定當前火車車廂的節數，如果當前節數超過最大的車廂節數，就 `std::invalid_argument`。
  - 方法： `int GetCarriage()`。取得當前火車車廂的節數。
  - 方法： `void SetMaxCarriage(int value)`。設定火車最大車廂的節數，最大不超過 `12`，如果超過就 `std::invalid_argument`。
  - 方法： `int GetMaxCarriage()`。取得當前火車最大車廂的節數。
  - 方法： `virtual FuelType GetFuelType() override`。請查看表格一，回傳相應的燃油類型。
  - 方法： `virtual void ConsumeDurability() override`。請查看表格二，減少載具的耐久值。如果耐久值小於 `0` 的時候，則 `std::runtime_error`。

<!--     - 成員： `int currentAltitude`。紀錄當前火車車廂的節數。
    - 成員： `int maxAltitude`。紀錄最大火車車廂能拉的節數。 -->

- 建構子類別： `Plane`，繼承 `Vehicle` 類別。

  - 建構子： `Plane(std::string country, std::string model, int durability, VehicleType type, int currentAltitude, int maxAltitude)`。初始化成員，並檢查整數類型的成員範圍若小於零，請丟出 `invalid_argument`。如果當前飛機的高度超過最大值，就 `std::invalid_argument`。飛機的最大飛行高度，如果不超過 `40000`，如果超過就 `std::invalid_argument`。
  - 方法： `void SetCurrentAltitude(int value)`。設定當前飛機的飛行高度，如果當前飛機的高度超過最大值，就 `std::invalid_argument`。
  - 方法： `void SetMaxAltitude(int value)`。設定飛機的最大飛行高度，如果不超過 `40000`，如果超過就 `std::invalid_argument`。
  - 方法： `int GetCurrentAltitude()`。取得當前飛機的飛行高度。
  - 方法： `int GetMaxAltitude()`。取得當前飛機的最大飛行高度。
  - 方法： `virtual FuelType GetFuelType() override`。請查看表格一，回傳相應的燃油類型。
  - 方法： `virtual void ConsumeDurability() override`。請查看表格二，減少載具的耐久值。如果耐久值小於 `0` 的時候，則 `std::runtime_error`。

- 建構子類別： `Bus`，繼承 `Vehicle` 類別。
  - 建構子： `Bus(std::string country, std::string model, int durability, VehicleType type, int wheel, int maxSpeed)`。初始化成員，並檢查整數類型的成員範圍若小於零，請丟出 `std::invalid_argument`。巴士的車輪數最大不能超過 `12` 顆，超過範圍就 `std::invalid_argument`。巴士最大速度，其不能超過 `80` 公里，超過範圍就 `std::invalid_argument`。
  - 方法： `void SetWheel(int value)`。製作巴士的車輪數，最大不能超過 `12` 顆，超過範圍就 `std::invalid_argument`。
  - 方法： `void SetMaxSpeed(int value)`。設定巴士最大速度，其不能超過 `80` 公里，超過範圍就 `std::invalid_argument`。
  - 方法： `int GetWheel()`。去得巴士的車輪數。
  - 方法： `int GetMaxSpeed()`。取得巴士最大的速度。
  - 方法： `virtual FuelType GetFuelType() override`。請查看表格一，回傳相應的燃油類型。
  - 方法： `virtual void ConsumeDurability() override`。請查看表格二，減少載具的耐久值。如果耐久值小於 `0` 的時候，則 `std::runtime_error`。
- 建構子類別： `Boat`，繼承 `Vehicle` 類別。
  - 說明：航行滑動狀態的初始值為 `false`。
    <!-- - 成員： `int isSailing`。紀錄汽車的車輪數。
    - 成員： `int maxSpeed`。紀錄汽車的車輪數。 -->
  - 建構子： `Boat(std::string country, std::string model, int durability, VehicleType type, int maxSpeed)`。初始化成員，並檢查整數類型的成員範圍若小於零，請丟出 `std::invalid_argument`。船的最大速度，不能超過 `30` 節，超過範圍就 `std::invalid_argument`。
  - 方法： `void SetSailing(bool status)`。設定是否船隻正在滑動。
  - 方法： `void SetMaxSpeed(int value)`。設定船的最大速度，不能超過 `30` 節，超過範圍就 `std::invalid_argument`。
  - 方法： `bool GetSailing()`。取得當前船隻的滑動狀態。
  - 方法： `int GetMaxSpeed()`。取得當前船隻的最大速度。
  - 方法： `virtual FuelType GetFuelType() override`。請查看表格一，回傳相應的燃油類型。
  - 方法： `virtual void ConsumeDurability() override`。請查看表格二，減少載具的耐久值。如果耐久值小於 `0` 的時候，則 `std::runtime_error`。

### 任務二、生產載具 - 20%

- 在日本生產： `FactoryJapan.hpp`
  - 命名空間: `Factory`
    - 命名空間： `Japan`
      - 函數： `std::shared_ptr<Bus> ProduceBus()`。根據表格三，回傳對應的物件。
      - 函數： `std::shared_ptr<Plane> ProducePlane()`。根據表格三，回傳對應的物件。
      - 函數： `std::shared_ptr<Boat> ProduceBoat()`。根據表格三，回傳對應的物件。
      - 函數： `std::shared_ptr<Train> ProduceTrain()`。根據表格三，回傳對應的物件。
- 在美國生產： `FactoryUSA.hpp`
  - 命名空間: `Factory`
    - 命名空間： `USA`
      - 函數： `std::shared_ptr<Bus> ProduceBus()`。根據表格三，回傳對應的物件。
      - 函數： `std::shared_ptr<Plane> ProducePlane()`。根據表格三，回傳對應的物件。
      - 函數： `std::shared_ptr<Boat> ProduceBoat()`。根據表格三，回傳對應的物件。
      - 函數： `std::shared_ptr<Train> ProduceTrain()`。根據表格三，回傳對應的物件。

> Hint：shared_ptr 和 make_shared 的方式長的像這樣。

```cpp
std::shared_ptr<Bus> bus = std::make_shared<Bus>(...);
```

### 任務三、載具子系統 - 30%

在實作建構子或者方法/函式的時候，當有整數型別參數傳入時，必須檢查是否小於 `0`。否則 `std::invalid_argument`。

- 售票管理系統： `TicketSystem.hpp`

  - 建構子： `TicketSystem(
        const std::shared_ptr<Boat>  boat,
        const std::shared_ptr<Bus>   bus,
        const std::shared_ptr<Plane> plane,
        const std::shared_ptr<Train> train
)`。初始化成員，傳入四個載具的物件資訊。
  - 方法：`Ticket BuyTicket(
std::string name,
Station     start,
Station     end,
VehicleType type,
Discount    discount,
int        distance)`。作為訂票系統。不過在訂票之前，你需要自行製作並維護載具座位表的容量，並檢查載具的座位量是否已經達到上限，不然就 `std::invalid_argument`，然後再根據載具類型，生成不同的票據資訊，增加當前載具的座位佔用量。更多資訊請查看表格四、五、六。
  - 方法： `void Depart(VehicleType type)`。作為指定載具發車的功能。在發車之前會先檢查載具是否損壞，再來載具是否燃油不足。如果上述情況就 `std::runtime_error`。最後都沒有上述情況時，他會重設指定載具的座位空間，並對載具增加損耗。當中你會需要使用到載具子系統內的四個物件資訊，並且由於你會需要使用到四個子類別轉型成父類別的功能，因此以下是範例。

    ```cpp
    // 父類別載具
    void Depart(VehicleType type) {
    // ...
    std::shared_ptr<Vehicle> vehicle;
    switch (type) {
        case VehicleType::BOAT: vehicle = Transform::UpCasting<Boat>(_boat); break;
        case VehicleType::BUS:  vehicle = Transform::UpCasting<Bus>(_car); break;
        case VehicleType::TRAIN: vehicle = Transform::UpCasting<Train>(_train); break;
        case VehicleType::PLANE: vehicle = Transform::UpCasting<Plane>(_plane); break;
    }
    // ...
    }

    ```

    - `Transform::UpCasting<型別>` 存在於 `include/TransformLayer.hpp` 當中。

- 維修載具函數： `MaintenanceSystem.hpp`
  - 說明： `void RepairVehicle(std::shared_ptr<Vehicle> vehicle)`。作用為維修載具，將載具的耐久值重新提高到最大值。
- 加電油站系統： `EnergyStation.hpp`
  - 說明：充電量和燃油值的初始值為 `0`。站體內，電量最大不得超過 `10000`，燃油量最大不得超過 `3000`。
  - 方法： `void AddPower(int value)`。增加站內的充電量，且站體內充電量最大不得超過 `10000`。
  - 方法： `void AddFuel(int value)`。增加站內的燃料量，且站體內燃油量最大不得超過 `3000`。
  - 方法： `int GetPower()`。取得站內的充電量。
  - 方法： `int GetFuel()`。取得站類的燃料量。
  - 方法： `void ChargeVehicle(std::shared_ptr<Vehicle> vehicle)`。 作用為對載具做充電的行為。當載具被傳入的時候，他會偵測載具的充電類型為燃油或者電能，並做出相對應的充電方式。但在載具充電完成之後，隨之站體內的燃油或者電量也會減少相對應的值。

---

## 期中迷因

店員： "請問有載具嗎"

客人：![b243d8912a436b98709c34d8f9ee223b](https://hackmd.io/_uploads/HJqRv4mfkl.jpg)

<!-- # Target 2

你需要重新製作一個腳踏車的載具（bicycle），雖然他並不會融入到載具子系統裡面，但是我們會測試一些載具所擁有的通用屬性。例如：載具的生產國家（country），載具的生產工廠（model）以及改變載具的種類（VehicleType）。

- 載具種類（VehicleType）
    在先前 Target 1. 裡面，我們定義了 VehicleType， -->

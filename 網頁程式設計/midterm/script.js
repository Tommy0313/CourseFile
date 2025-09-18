const canvas = document.getElementById('gameCanvas');
const ctx = canvas.getContext('2d');
const blockSize = 30; // 每個區塊大小
const rows = 20;
const cols = 10;

let grid = Array.from({ length: rows }, () => Array(cols).fill(0));
let gameInterval;
let speed = 1000;
let currentBlock;
let gameOver = false;
let reset = true;

const shapes = [
    [[1, 1, 1], [0, 1, 0]], // T-shape
    [[1, 1, 1, 1]], // I-shape
    [[1, 1], [1, 1]], // Square
    [[1, 1, 0], [0, 1, 1]], // Z-shape
    [[1, 1, 1], [0, 0, 1]], // L-shape
];

/*
function drawFlying2024(callback) {
    const text = "2024";
    const fontSize = 48;
    let y = -fontSize; // 初始位置在畫布上方
    const x = canvas.width / 2 - ctx.measureText(text).width / 2; // 水平居中
    const dy = 2; // 每幀的垂直移動速度

    function animate() {
        ctx.clearRect(0, 0, canvas.width, canvas.height); // 清除畫布
        ctx.font = `${fontSize}px Arial`;
        ctx.fillStyle = randomColor();
        ctx.fillText(text, x, y); // 繪製文字
        y += dy; // 更新位置

        if (y < canvas.height + 50) {
            requestAnimationFrame(animate); // 繼續動畫
        } else {
            if (callback) callback(); // 動畫結束後執行回呼（例如開始遊戲）
        }
    }

    animate();
}
*/

//開頭2024方塊動畫 由上到下
function drawFlying2024(callback) {
    let blockSize = 17;
    const blocks2024 = [
        // "2"
        { shape: [[1, 1, 1], [0, 0, 1], [1, 1, 1], [1, 0, 0], [1, 1, 1]], x: 1, y: -6 },
        // "0"
        { shape: [[1, 1, 1], [1, 0, 1], [1, 0, 1], [1, 0, 1], [1, 1, 1]], x: 5, y: -6 },
        // "2"
        { shape: [[1, 1, 1], [0, 0, 1], [1, 1, 1], [1, 0, 0], [1, 1, 1]], x: 9, y: -6 },
        // "4"
        { shape: [[1, 0, 1], [1, 0, 1], [1, 1, 1], [0, 0, 1], [0, 0, 1]], x: 13, y: -6 },
    ];

    let yOffset = -blockSize * 5; // 初始位置在畫布上方
    const speed = 2; // 移動速度

    function animate() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);

        blocks2024.forEach(block => {
            ctx.fillStyle = randomColor();
            block.shape.forEach((row, dy) => {
                row.forEach((cell, dx) => {
                    if (cell) {
                        ctx.fillRect(
                            (block.x + dx) * blockSize,
                            (block.y + dy) * blockSize + yOffset,
                            blockSize,
                            blockSize
                        );
                        ctx.strokeRect(
                            (block.x + dx) * blockSize,
                            (block.y + dy) * blockSize + yOffset,
                            blockSize,
                            blockSize
                        );
                    }
                });
            });
        });

        yOffset += speed;

        if (yOffset < canvas.height * 1.2) {
            requestAnimationFrame(animate);
        } else {
            if (callback) callback();
        }
    }

    animate();
}


//開頭2024動畫
drawFlying2024();

//隨機顏色
function randomColor() {
    const r = Math.floor(Math.random() * 256);
    const g = Math.floor(Math.random() * 256);
    const b = Math.floor(Math.random() * 256);
    return `rgb(${r}, ${g}, ${b})`;
}

//偵測是否有與現在畫面上的方塊重疊 主要用於防止最後遊戲結束前的方塊佔據bug
function isOverlapping(block) {

    for (let row = 0; row < block.shape.length; row++) {
        for (let col = 0; col < block.shape[row].length; col++) {
            if (block.shape[row][col]) {
                const gridX = block.x + col;
                const gridY = block.y + row;

                // 如果超出邊界或與現有方塊重疊，返回 true
                if (gridY >= rows || gridX < 0 || gridX >= cols || grid[gridY][gridX]) {
                    return true;
                }
            }
        }
    }

    return false; // 無重疊則返回 false
}

//隨機建立方塊於最上方
function createBlock() {
    const shape = shapes[Math.floor(Math.random() * shapes.length)];
    const color = randomColor();
    let newBlock = { shape, x: Math.floor((cols - shape[0].length) / 2), y: 0, color };

    // 當新方塊與現有方塊重疊時，自動上移
    if (isOverlapping(newBlock)) {
        newBlock.y -= 1; // 方塊往上移動
        if (newBlock.y < 0) {
            drawBlock(newBlock);
            endGame();
            return null;
        }
    }

    return newBlock; // 返回修正後的新方塊
}


//畫每一格有顏色的方塊
function drawGrid() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    grid.forEach((row, y) => {
        row.forEach((cell, x) => {
            if (cell) {
                const gradient = ctx.createLinearGradient(x* blockSize, y* blockSize, x* blockSize + blockSize, y* blockSize + blockSize);
                gradient.addColorStop(0, cell); // 開始顏色
                gradient.addColorStop(1, "white"); // 結束顏色
                ctx.fillStyle = gradient;
                ctx.fillRect(x * blockSize, y * blockSize, blockSize, blockSize);
                ctx.strokeRect(x * blockSize, y * blockSize, blockSize, blockSize);
            }
        });
    });
}

//最大值
function Max(a, b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

//最小值
function Min(a, b){
    if(a > b){
        return b;
    }
    else{
        return a;
    }
}

//畫方塊功能
function drawBlock(block) {
    let min_x = 999;
    let min_y = 999;
    let max_x = 0;
    let max_y = 0;


    block.shape.forEach((row, dy) => {
        row.forEach((cell, dx) => {
            if (cell) {
                const x = (block.x + dx) * blockSize;
                const y = (block.y + dy) * blockSize;
                min_x = Min(min_x,x);
                min_y = Min(min_y,y);
                max_x = Max(max_x,x);
                max_y = Max(max_y,y);
                const gradient = ctx.createLinearGradient(x, y, x + blockSize, y + blockSize);
                gradient.addColorStop(0, block.color); // 開始顏色
                gradient.addColorStop(1, "white"); // 結束顏色
                ctx.fillStyle = gradient;
            
                ctx.fillRect(x, y, blockSize, blockSize);
                ctx.strokeStyle = "black";
                ctx.strokeRect(x, y, blockSize, blockSize);
            }
        });
    });
    if (block.status === 'selected') {
        ctx.strokeStyle = 'red';
        ctx.lineWidth = 2;
        ctx.strokeRect(min_x, min_y, max_x-min_x + blockSize, max_y-min_y + blockSize);
        ctx.lineWidth = 1;
        ctx.strokeStyle = 'black';
    }

}

let wait = false;


//移動方塊
function moveBlock(dx, dy) {
    if (!checkCollision(currentBlock, dx, dy)) {
        currentBlock.x += dx;
        currentBlock.y += dy;
    } else if (dy > 0) {
        mergeBlock();
        clearLines();
        if (checkGameOver()) {
            endGame();
        } else {
            wait = true;
            currentBlock = null;
            setTimeout(() => {
                currentBlock = createBlock();
                wait = false;
            }, 5000); // 5 秒後創建新方塊
        }
    }
}

//方塊順時鐘旋轉功能
function rotateBlock() {
    const newShape = currentBlock.shape[0].map((_, i) =>
        currentBlock.shape.map(row => row[i]).reverse()
    );
    if (!checkCollision({ ...currentBlock, shape: newShape }, 0, 0)) {
        currentBlock.shape = newShape;
    }
}

//偵測是否一排都有方塊
function checkCollision(block, dx, dy) {
    return block.shape.some((row, y) =>
        row.some((cell, x) => {
            if (cell) {
                const newX = block.x + x + dx;
                const newY = block.y + y + dy;
                return newX < 0 || newX >= cols || newY >= rows || grid[newY]?.[newX];
            }
            return false;
        })
    );
}

//將顏色填入格子array中
function mergeBlock() {
    currentBlock.shape.forEach((row, dy) =>
        row.forEach((cell, dx) => {
            if (cell) {
                grid[currentBlock.y + dy][currentBlock.x + dx] = currentBlock.color;
            }
        })
    );
}

//清除一排的方塊
function clearLines() {
    grid = grid.filter(row => row.some(cell => !cell));
    while (grid.length < rows) {
        grid.unshift(Array(cols).fill(0));
    }
}

//檢查是否遊戲結束
function checkGameOver() {
    return grid[0].some(cell => cell);
}


//遊戲結束抖動紅色動畫
function gameOverAnimation(callback) {
    const text = "GAME OVER";
    const fontSize = 50;
    const bloodDrops = [];
    const maxDrops = 150; // 增加血滴數量
    const gravity = 1.2;  // 模擬重力加強
    const speedXRange = [-3, 3]; // 血滴橫向速度範圍
    const canvasCenterX = canvas.width / 2;
    const canvasCenterY = canvas.height / 3;
    let backgroundAlpha = 0; // 背景透明度逐漸增加
    let shakeMagnitude = 5; // 文字震動幅度

    // 初始化血滴數據
    for (let i = 0; i < maxDrops; i++) {
        bloodDrops.push({
            x: canvasCenterX + Math.random() * 200 - 100,
            y: canvasCenterY + fontSize / 2,
            vx: Math.random() * (speedXRange[1] - speedXRange[0]) + speedXRange[0],
            vy: Math.random() * -4,
            radius: Math.random() * 3 + 2
        });
    }

    function animate() {
        // 逐漸加深背景顏色
        ctx.fillStyle = `rgba(50, 0, 0, ${Math.min(backgroundAlpha, 0.8)})`;
        ctx.fillRect(0, 0, canvas.width, canvas.height);
        backgroundAlpha += 0.01;

        // 繪製 "Game Over" 文字
        const textX = canvasCenterX + Math.random() * shakeMagnitude - shakeMagnitude / 2;
        const textY = canvasCenterY + Math.random() * shakeMagnitude - shakeMagnitude / 2;

        ctx.font = `${fontSize}px 'Horror Type'`;
        ctx.fillStyle = "red";
        ctx.textAlign = "center";
        ctx.fillText(text, textX, textY);

        // 繪製血滴
        bloodDrops.forEach(drop => {
            ctx.fillStyle = "rgba(200, 0, 0, 0.8)";
            ctx.beginPath();
            ctx.arc(drop.x, drop.y, drop.radius, 0, Math.PI * 2);
            ctx.fill();

            // 更新血滴位置
            drop.x += drop.vx;
            drop.y += drop.vy;
            drop.vy += gravity;

            // 如果血滴超出畫布範圍，重新生成
            if (drop.y > canvas.height + drop.radius) {
                drop.x = canvasCenterX + Math.random() * 200 - 100;
                drop.y = canvasCenterY + fontSize / 2;
                drop.vy = Math.random() * -4;
            }
        });

        // 持續動畫
        if (gameOver) {
            requestAnimationFrame(animate);
        } else {
            if (callback) callback();
        }
    }

    animate();
}


//結束遊戲功能
function endGame() {
    currentBlock = null;
    clearInterval(gameInterval);
    gameOver = true;

    // 開始動畫
    gameOverAnimation();
}



let number = 0;
let flash_speed = 10;

//更新遊戲狀態
function update() {
    if (!gameOver) {
        number +=flash_speed;
        if(number>speed){
            if(!wait){
                if (selectedBlock == null) {
                    moveBlock(0, 1);    
                }
            }
            number = 0;
        }
        drawGrid();
        drawBlock(currentBlock);
    }
    
}

let selectedBlock = null;

//滑鼠按下
canvas.addEventListener('mousedown', (event) => {
    const mouseX = event.offsetX;
    const mouseY = event.offsetY;

    // 檢查是否點擊了某個活著的方塊
    if (currentBlock && isInsideBlock(mouseX, mouseY, currentBlock)) {
        selectedBlock = currentBlock;
        selectedBlock.status = 'selected';
    }
});

//偵測方塊是否有重疊 主要用於滑鼠拖曳時
function isOverlapping2(block, x, y) {

    for (let row = 0; row < block.shape.length; row++) {
        for (let col = 0; col < block.shape[row].length; col++) {
            if (block.shape[row][col]) {
                const gridX = x + col;
                const gridY = y + row;

                // 如果超出邊界或與現有方塊重疊，返回 true
                if (gridY >= rows || gridX < 0 || gridX >= cols || grid[gridY][gridX]) {
                    return true;
                }
            }
        }
    }

    return false; // 無重疊則返回 false
}

//滑鼠拖曳方塊移動
canvas.addEventListener('mousemove', (event) => {
    if (selectedBlock) {
        const mouseX = event.offsetX;
        const mouseY = event.offsetY;

        // 計算新位置
        const newX = Math.floor(mouseX / blockSize);
        const newY = Math.floor(mouseY / blockSize);

        // 檢查是否超出邊界或與已放置方塊重疊
        if (
            newX >= 0 &&
            newX < cols &&
            newY >= 0 &&
            newY < rows &&
            (!isOverlapping2(selectedBlock, newX, newY)) // 確保新位置沒有放置方塊
        ) {
            // 更新選中方塊的位置
            selectedBlock.x = newX;
            selectedBlock.y = newY;
            
            // 重新繪製
            drawGrid();
            drawBlock(selectedBlock);
        }
    }
});

//滑鼠放開
canvas.addEventListener('mouseup', () => {
    if (selectedBlock) {
        selectedBlock.status = 'alive'; // 取消選中狀態
        selectedBlock = null;
    }
});

// 判定滑鼠是否在方塊內
function isInsideBlock(mouseX, mouseY, block) {
    return block.shape.some((row, dy) =>
        row.some((cell, dx) => {
            if (cell) {
                const blockX = (block.x + dx) * blockSize;
                const blockY = (block.y + dy) * blockSize;
                return mouseX >= blockX && mouseX <= blockX + blockSize &&
                       mouseY >= blockY && mouseY <= blockY + blockSize;
            }
            return false;
        })
    );
}

//初始化遊戲
function initGame() {
    grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    currentBlock = createBlock();
    drawGrid();
    drawBlock(currentBlock);
}

//開始遊戲
document.getElementById('startButton').addEventListener('click', () => {
    if (reset){
        initGame();
        reset = false;
    }
    if (!gameInterval) {
        gameInterval = setInterval(update, flash_speed);
    }
});

//暫停遊戲
document.getElementById('pauseButton').addEventListener('click', () => {
    clearInterval(gameInterval);
    gameInterval = null;
});

//重置遊戲
document.getElementById('resetButton').addEventListener('click', () => {
    reset = true;
    gameOver = false;
    clearInterval(gameInterval);
    gameInterval = null;

    // 清空畫布
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    drawFlying2024();
});




document.getElementById('leftButton').addEventListener('click', () => moveBlock(-1, 0));
document.getElementById('rightButton').addEventListener('click', () => moveBlock(1, 0));
document.getElementById('rotateButton').addEventListener('click', rotateBlock);

//調整方塊移動速度
document.getElementById('speedUpButton').addEventListener('click', () => (speed = Math.max(100, speed - 100)));
document.getElementById('speedDownButton').addEventListener('click', () => (speed = Math.min(2000, speed + 100)));

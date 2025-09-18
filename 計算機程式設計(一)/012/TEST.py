def autoCool(temperature, wind, humidity):
    if temperature > 30 and wind == 0 or humidity > 85:
        print('開冷氣')


autoCool(31, 0, 86)  # TTT 123
autoCool(32, 0, 80)  # TTF 123
autoCool(33, 1, 87)  # TFT 123
autoCool(34, 2, 79)  # TFF 12
autoCool(29, 0, 88)  # FTT 123
autoCool(28, 0, 78)  # FTF 12
autoCool(22, 3, 90)  # FFT 123
autoCool(24, 4, 81)  # FFF 12
import cv2
import numpy as np
import matplotlib.pyplot as plt

# 讀取你下載的圖片 (請確認檔名正確，並轉為灰階)
img = cv2.imread('image_bbaa08.jpg', cv2.IMREAD_GRAYSCALE)
h, w = img.shape

# 觀察圖片，垂直的雜訊區塊大約重複了 13 次
# 我們估計基礎週期 T 大約是 圖片寬度 / 13
period_estimate = w // 13

fig, axes = plt.subplots(3, 3, figsize=(12, 8))
axes = axes.flatten()

# 測試基礎週期附近的偏移量，尋找最清晰的解碼結果
for i, shift in enumerate(range(period_estimate - 4, period_estimate + 5)):
    # 將圖片向右平移 shift 個像素
    shifted = np.roll(img, shift, axis=1)
    
    # 計算差異：|f(x, y) - f(x + T, y)|
    diff = cv2.absdiff(img, shifted)
    
    # 強化對比度讓字體更明顯
    diff = cv2.equalizeHist(diff)
    
    axes[i].imshow(diff, cmap='gray')
    axes[i].set_title(f'Shift: {shift} px')
    axes[i].axis('off')

plt.tight_layout()
plt.savefig('F_answer.png')
plt.show()
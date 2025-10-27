# 🌤️ Arduino Weather Station - محطة الطقس الذكية

> محطة طقس ذكية متكاملة بالأردوينو تقيس درجة الحرارة والرطوبة والإضاءة مع شاشة OLED وتخزين البيانات

![Arduino Weather Station](https://images.unsplash.com/photo-1558618047-3c8c76ca7d13?w=800&h=400&fit=crop&crop=center)

## 📋 المحتويات

- [نظرة عامة](#نظرة-عامة)
- [المكونات المطلوبة](#المكونات-المطلوبة)
- [المخطط التخطيطي](#المخطط-التخطيطي)
- [التوصيلات](#التوصيلات)
- [تثبيت المكتبات](#تثبيت-المكتبات)
- [رفع الكود](#رفع-الكود)
- [الميزات](#الميزات)
- [صور المشروع](#صور-المشروع)
- [استكشاف الأخطاء](#استكشاف-الأخطاء)
- [روابط مفيدة](#روابط-مفيدة)

## 🎯 نظرة عامة

محطة الطقس الذكية هذه تستخدم Arduino Uno لقياس وعرض:
- 🌡️ **درجة الحرارة** (مئوية وفهرنهايت)
- 💧 **الرطوبة النسبية** (%)
- ☀️ **شدة الإضاءة** (مستوى الضوء)
- 📱 **إرسال البيانات** عبر البلوتوث
- 💾 **حفظ البيانات** في ذاكرة EEPROM

---

## 🔧 المكونات المطلوبة

| المكون | الصورة | الوصف | الكمية | السعر التقريبي |
|---------|---------|-------|---------|----------------|
| **Arduino Uno R3** | ![Arduino Uno](https://images.unsplash.com/photo-1553406830-ef2513450d76?w=200&h=150&fit=crop) | المتحكم الرئيسي للمشروع | 1 | $25 |
| **DHT22 Sensor** | ![DHT22](https://images.unsplash.com/photo-1581092786450-1fc1b7c3e2e5?w=200&h=150&fit=crop) | حساس الحرارة والرطوبة عالي الدقة | 1 | $10 |
| **LDR Sensor** | ![LDR](https://images.unsplash.com/photo-1581092580297-87f6b0c2b2b8?w=200&h=150&fit=crop) | مقاوم ضوئي لقياس شدة الإضاءة | 1 | $2 |
| **OLED SSD1306** | ![OLED Display](https://images.unsplash.com/photo-1558618666-fcd25c85cd64?w=200&h=150&fit=crop) | شاشة عرض OLED 128×64 بكسل | 1 | $8 |
| **HC-05 Bluetooth** | ![Bluetooth Module](https://images.unsplash.com/photo-1606986628253-38cd2eb6bb76?w=200&h=150&fit=crop) | وحدة البلوتوث للاتصال اللاسلكي | 1 | $6 |
| **مقاومات** | ![Resistors](https://images.unsplash.com/photo-1581092582424-d2b1b4e5b6fb?w=200&h=150&fit=crop) | 10kΩ للـ LDR و 220Ω للـ LED | حسب الحاجة | $3 |
| **أسلاك توصيل** | ![Jumper Wires](https://images.unsplash.com/photo-1558618047-3c8c76ca7d13?w=200&h=150&fit=crop) | أسلاك ذكر-أنثى وذكر-ذكر | 1 مجموعة | $5 |
| **Breadboard** | ![Breadboard](https://images.unsplash.com/photo-1518717758536-85ae29035b6d?w=200&h=150&fit=crop) | لوحة التجارب للتوصيلات | 1 | $5 |

**💰 التكلفة الإجمالية التقريبية: $64**

---

## 🔌 التوصيلات

### Arduino Uno → DHT22
```
VCC  → 3.3V
GND  → GND
DATA → Pin 2
```

### Arduino Uno → OLED SSD1306
```
VCC → 3.3V
GND → GND
SCL → A5
SDA → A4
```

### Arduino Uno → LDR Sensor
```
LDR Pin 1 → A0
LDR Pin 2 → 10kΩ Resistor → GND
VCC → 5V → 10kΩ Resistor → A0
```

### Arduino Uno → HC-05 Bluetooth
```
VCC → 3.3V
GND → GND
RX  → Pin 3
TX  → Pin 4
```

---

## 🛠️ المخطط التخطيطي

![Circuit Diagram](https://raw.githubusercontent.com/KaizerAE/arduino-weather-station/main/circuit-diagram.png)

*المخطط يوضح جميع التوصيلات بين المكونات بشكل واضح*

---

## 📚 تثبيت المكتبات

قم بتثبيت المكتبات التالية من مدير المكتبات في Arduino IDE:

```cpp
// المكتبات المطلوبة
#include <DHT.h>           // لحساس DHT22
#include <Adafruit_GFX.h>  // للرسوميات
#include <Adafruit_SSD1306.h> // لشاشة OLED
#include <SoftwareSerial.h>    // للبلوتوث
#include <EEPROM.h>            // لحفظ البيانات
```

**خطوات التثبيت:**
1. افتح Arduino IDE
2. اذهب إلى `Tools` > `Manage Libraries`
3. ابحث عن كل مكتبة واضغط `Install`

---

## ⬆️ رفع الكود

1. **تحميل الكود:**
   ```bash
   git clone https://github.com/KaizerAE/arduino-weather-station.git
   cd arduino-weather-station
   ```

2. **فتح الملف:**
   - افتح ملف `weather_station.ino` في Arduino IDE

3. **اختيار اللوحة:**
   - `Tools` > `Board` > `Arduino Uno`

4. **اختيار المنفذ:**
   - `Tools` > `Port` > اختر المنفذ الصحيح

5. **رفع الكود:**
   - اضغط على زر الرفع ⬆️

---

## ✨ الميزات

- 🎮 **واجهة بديهية** مع شاشة OLED واضحة
- 🔄 **تحديث مستمر** للبيانات كل 5 ثوان
- 📱 **اتصال بلوتوث** لمراقبة البيانات عن بعد
- 💾 **حفظ البيانات** في EEPROM لمنع فقدانها
- ⚡ **استهلاك منخفض** للطاقة
- 🌡️ **دقة عالية** في القياسات
- 🔔 **تنبيهات** عند تجاوز الحدود المحددة

---

## 📸 صور المشروع

### التجميع النهائي
![Final Assembly](https://images.unsplash.com/photo-1581092786450-1fc1b7c3e2e5?w=600&h=400&fit=crop)

### شاشة العرض
![Display Output](https://images.unsplash.com/photo-1558618666-fcd25c85cd64?w=600&h=400&fit=crop)

### التوصيلات
![Wiring](https://images.unsplash.com/photo-1518717758536-85ae29035b6d?w=600&h=400&fit=crop)

---

## 🐛 استكشاف الأخطاء

### مشاكل شائعة وحلولها:

| المشكلة | السبب المحتمل | الحل |
|----------|---------------|------|
| الشاشة لا تعمل | توصيلات خاطئة | تأكد من توصيل SDA/SCL بشكل صحيح |
| قراءات خاطئة من DHT22 | تأخير غير كاف | أضف delay(2000) بين القراءات |
| البلوتوث لا يتصل | إعدادات خاطئة | تأكد من Baud Rate 9600 |
| استهلاك عالي للطاقة | حلقة مستمرة | أضف وضع النوم sleep mode |

### رسائل خطأ شائعة:
- ❌ `DHT sensor error` → تحقق من التوصيلات
- ❌ `OLED not found` → تأكد من عنوان I2C
- ❌ `Memory full` → امسح بيانات EEPROM

---

## 🔗 روابط مفيدة

### للمبتدئين:
- 📖 [دليل Arduino للمبتدئين](https://www.arduino.cc/en/Guide)
- 🎥 [فيديوهات تعليمية](https://www.youtube.com/playlist?list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP)
- 📚 [كتاب البرمجة بـ C++](https://www.learncpp.com/)

### وثائق المكونات:
- 🌡️ [DHT22 Datasheet](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
- 📺 [SSD1306 OLED Guide](https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/)
- 📡 [HC-05 Bluetooth Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-05-bluetooth-module-tutorial/)

### أدوات مفيدة:
- 🛠️ [Arduino IDE](https://www.arduino.cc/en/software)
- 📱 [تطبيق Bluetooth Terminal](https://play.google.com/store/apps/details?id=Qwerty.BluetoothTerminal)
- 🔧 [Fritzing للمخططات](https://fritzing.org/)

### مجتمعات الدعم:
- 💬 [منتدى Arduino](https://forum.arduino.cc/)
- 🗨️ [Reddit Arduino](https://www.reddit.com/r/arduino/)
- 📧 [Stack Overflow](https://stackoverflow.com/questions/tagged/arduino)

---

## 🤝 المساهمة

نرحب بمساهماتكم! يمكنكم:
- 🐞 الإبلاغ عن الأخطاء
- 💡 اقتراح ميزات جديدة
- 🔧 إرسال Pull Requests
- 📝 تحسين التوثيق

---

## 📄 الترخيص

هذا المشروع مرخص تحت رخصة MIT - راجع ملف [LICENSE](LICENSE) للتفاصيل.

---

## 👨‍💻 المطور

**KaizerAE**
- GitHub: [@KaizerAE](https://github.com/KaizerAE)
- 📧 للاستفسارات والدعم

---

⭐ **إذا أعجبك المشروع، لا تنسى إعطاء نجمة للمستودع!** ⭐

---

*تم إنشاء هذا المشروع بحب ❤️ لمجتمع الصناع والمطورين*

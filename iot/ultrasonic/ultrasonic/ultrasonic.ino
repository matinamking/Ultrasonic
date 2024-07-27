// اضافه کردن کتابخانه LiquidCrystal


#include "LiquidCrystal.h"

// تعریف پین‌های مورد استفاده
const int trigPin = 2;
const int echoPin = 3;

// ایجاد یک شیء از کلاس LiquidCrystal با نام lcd و تعیین پین‌های مورد استفاده
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);

void setup() {
  // شروع ارتباط با Serial
  Serial.begin(9600);
  
  // تنظیمات اولیه LCD
  lcd.begin(16, 2);
  lcd.clear();  // پاک کردن صفحه
  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");  // نمایش پیام متنی
  
  // تنظیمات پین‌ها
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);  // تاخیر ۱ ثانیه
}

void loop() {
  lcd.clear();  // پاک کردن صفحه LCD

  // ارسال پالس فرستنده فاصله
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // خواندن مدت زمان بازگشت امواج از ماژول UltraSonic
  long duration = pulseIn(echoPin, HIGH);
  
  // محاسبه مقدار فاصله به سانتی‌متر
  long distance_cm = duration / 58.2;

  // نمایش فاصله در LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance_cm);
  lcd.print(" cm");

  delay(1000);  // تاخیر ۱ ثانیه
}

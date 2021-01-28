//AKE Remake
//AKE Electronic

int sensitive = 185; // สำหรับ 5A
// int sensitive = 100; // สำหรับ 20A
// int sensitive = 66; // สำหรับ 30A
 
int offset = 2525; // ค่าเริ่มต้น 2500 ปรับค่าตรงนี้เพื่อให้ค่ายังไม่มีโหลดเป็น 0.00

void setup() {
  // เซ็ตพอร์ตที่ใช้ในการเชื่อมต่อ 9600
  Serial.begin(9600);
}

// กำหนดลูปวนซ้ำการทำงาน
void loop() {
  // กำหนดพอร์ตอินพุตสัญญาณเข้า อนาล็อกที่ขา A0
  int sensorValue = analogRead(A0);
  // บอร์ดสามารถอ่านค่าได้ตั้งแต่ ( 0 - 1023) และ โวลต์ตั้งแต่ (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0); // บรรทัดนี้เป็นการนำค่าที่ได้ตั้งแต่ 0-1023 มาหารด้วย 1023.0 ก็จะได้เป็นโวลต์จริงครับ
  // แสดงค่าที่อ่านได้ออกทางพอร์ต9600ของโปรแกรมนั่นเองครับ

  double Am = getCA();

  Serial.print("แรงดันแบตเตอรี่ : ");
  Serial.print(voltage);
  Serial.print(" V");

  Serial.print("\t");
 
  Serial.print("กระแสชาร์จ : ");
  Serial.print(Am); //ตัวแปรกระเเส
  Serial.println(" A");
  delay(1000);
 
}

  // หาค่ากระแสเฉลี่ย
  double getCA() {
  int count = 200;
  double sum = 0;
  for (int i = 0; i < count; i++) {
  sum += getC();
  }
  double val = sum / count;
  return val;
  }
  // อ่านค่ากระแส
  double getC() {
  int a = analogRead(A0);
  double v = ( a / 1024.0) * 5000;
  double c = (v - offset) / sensitive;
  return c;
  }
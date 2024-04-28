/**********************************************************************

【準備】
  I2Cで通信

RaspberrPy Pico W - ST7735
3.3V - VCC
GND  - GND
GP17 - CS(チップセレクト)
GP22 - RESET(リセット信号入力)
GP28 - DC(データ/コマンド制御)
GP19 - SDA(シリアルデータ入力)
GP18 - SCL(シリアルクロック)
未接続 - BL(バックライト制御)

**********************************************************************/

#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>
#include <SPI.h>

//ピン番号設定
#define TFT_DC      28  // DC
#define TFT_CS      17  // CS
#define TFT_SCLK    18  // Clock
#define TFT_SDA    19  // SDA
#define TFT_RST     22  // Reset 

//インスタンス生成
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI, TFT_CS, TFT_DC, TFT_RST);
double x=10,y=0;

void setup(void) 
{
  tft.initR(INITR_BLACKTAB);                //Init ST7735S初期化
  
  tft.fillScreen(ST77XX_BLACK);               //背景の塗りつぶし

  //テキスト表示
  tft.setRotation(3);                         //画面回転
  tft.setTextSize(3);                         //サイズ

  tft.setTextWrap(true);                     //テキスト自動折り返し
  //tft.printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
  /*
  tft.setCursor(0, 20);                      //カーソル位置                      
  tft.setTextColor(ST77XX_RED);              //赤
  tft.printf("MATY\n");

  tft.setTextColor(ST77XX_GREEN);            //緑
  tft.printf("MATY\n");

  tft.setTextColor(ST77XX_BLUE);             //青
  tft.printf("MATY\n");

  tft.setTextColor(ST77XX_YELLOW);           //黄
  tft.printf("MATY\n");
  */
}

void loop()
{
  tft.fillScreen(ST7735_BLACK); //黒画面で初期化
  
  // テキストサイズを設定
  tft.setTextSize(3);
  // テキスト色を設定
  tft.setTextColor(ST77XX_BLUE);
  // テキストの開始位置を設定
  tft.setCursor(0, 10);

  //ディスプレイの情報を取得し、表示
  tft.setTextSize(1);
  tft.printf("width*height\n");
  tft.printf("%d * %d\n",tft.width(),tft.height());
  tft.printf("Rotate\n");
  tft.printf("%d\n",tft.getRotation());


  // 1行目に"Hello"を表示
  //tft.println("Hello");
  // 2行目に"World!"を表示
  //tft.println("World!");

  //1秒ごとに文字を移動表示
  x += 10;
  y = 100;
  if(x > 100){
    x = 10;
  }
  tft.setCursor(x,y);
  tft.setTextSize(3);
  tft.printf("A");
  delay(1000);      //Xmsの遅延
}
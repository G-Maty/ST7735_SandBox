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
#include <Fonts/FreeSerifItalic9pt7b.h>

//ピン番号設定
#define TFT_DC      28  // DC
#define TFT_CS      17  // CS
#define TFT_SCLK    18  // Clock
#define TFT_SDA    19  // SDA
#define TFT_RST     22  // Reset 

//色設定
#define RED ST77XX_RED
#define BLUE ST77XX_BLUE

//インスタンス生成
Adafruit_ST7735 tft = Adafruit_ST7735(&SPI, TFT_CS, TFT_DC, TFT_RST);
double x=10,y=0;

void print_Displayinfo(void);
void moveChar(void);

void setup(void) 
{
  /* 基本的な使用法 */
  tft.initR(INITR_BLACKTAB);                //Init ST7735S初期化
  tft.fillScreen(ST77XX_BLACK);               //背景の塗りつぶし

  tft.setRotation(1);                         //画面回転
  // fillCircle(x座標,y座標,半径,色)　内部を塗りつぶす
  tft.fillCircle(10,10,5,RED);
  // fillCircle(x座標,y座標,半径,色)　内部を塗りつぶさない
  tft.drawCircle(30,40,20,BLUE);

  //fillRect(x,y,widh,high,color);
  tft.fillRect(50,10,30,10,RED);

  //drawLine(x0,y0,x1,y1,color); (x0,y0)から(x1,y1)に直線を引く
  tft.drawLine(30,30,50,50,BLUE);

  // setCursor(x,y); (x,y)にカーソル移動
  tft.setCursor(5,100);
  //サイズ設定：1 = 6*8
  tft.setTextSize(1);
  //フォント設定（includeも忘れずに）
  tft.setFont(&FreeSerifItalic9pt7b);
  tft.println("GMatyMaty");

  
  //tft.setTextSize(3);                         //サイズ

  //tft.setTextWrap(true);                     //テキスト自動折り返し
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

  // 1行目に"Hello"を表示
  //tft.println("Hello");
  // 2行目に"World!"を表示
  //tft.println("World!");
  */
 
}

void loop()
{
  //tft.fillScreen(ST7735_BLACK); //黒画面で初期化
  
  // テキストサイズを設定
  //tft.setTextSize(3);
  // テキスト色を設定
  //tft.setTextColor(ST77XX_BLUE);
  // テキストの開始位置を設定
  //tft.setCursor(0, 10);
  //print_Displayinfo();

  //moveChar();

  //delay(1000);      //Xmsの遅延
}

void print_Displayinfo(){
  //ディスプレイの情報を取得し、表示
  tft.setTextSize(1);
  tft.printf("width*height\n");
  tft.printf("%d * %d\n",tft.width(),tft.height());
  tft.printf("Rotate\n");
  tft.printf("%d\n",tft.getRotation());
}

void moveChar(){
  //1秒ごとに文字を移動表示
  x += 10;
  y = 100;
  if(x > 100){
    x = 10;
  }
  tft.setCursor(x,y);
  tft.setTextSize(3);
  tft.printf("A");
}
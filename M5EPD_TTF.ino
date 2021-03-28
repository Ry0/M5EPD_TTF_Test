//The Fonts file (M5EPD_TTF) used in the example is in the same path as the program, please install Fonts file in TF card or SPIFFS before compiling.

#include "M5EPD.h"
#include "FS.h"
#include "SPIFFS.h"
#include "binaryttf.h"

//Example for TTF font
//#define USE_SPIFFS

M5EPD_Canvas canvas1(&M5.EPD);

void setup()
{
  M5.begin();
  M5.TP.SetRotation(90);
  M5.EPD.SetRotation(90);
  M5.EPD.Clear(true);

  if (!SPIFFS.begin(true))
  {
    log_e("SPIFFS Mount Failed");
    while (1);
  }

#ifdef USE_SPIFFS
  canvas1.loadFont("/GenSenRounded-R.ttf", SPIFFS); // Load font files from SPIFFS
#elif USE_SD
  canvas1.loadFont("/GenSenRounded-R.ttf", SD); // Load font files from SD Card
#else
  canvas1.loadFont(binaryttf, sizeof(binaryttf)); // Load font files from binary data
#endif

  canvas1.createCanvas(540, 960);
  canvas1.createRender(48, 256);
  canvas1.setTextSize(48);
  canvas1.setTextColor(15);
  canvas1.setTextDatum(TL_DATUM);

  canvas1.drawString("ある日の暮方の事である。", 0, 0);
  canvas1.drawString("一人の下人げにんが、羅生", 0, 60);
  canvas1.drawString("門らしょうもんの下で雨や", 0, 120);
  canvas1.drawString("広い門の下には、この男の", 0, 180);
  canvas1.drawString("ほかに誰もいない。ただ、", 0, 240);
  canvas1.drawString("所々丹塗にぬりの剥はげた", 0, 300);
  canvas1.drawString("、大きな円柱まるばしらに", 0, 360);
  canvas1.drawString("蟋蟀きりぎりすが一匹とま", 0, 420);
  canvas1.drawString("っている。羅生門が、朱雀", 0, 480);
  canvas1.drawString("大路すざくおおじにある以", 0, 540);
  canvas1.drawString("上は、この男のほかにも、", 0, 600);
  canvas1.drawString("雨やみをする市女笠いちめ", 0, 660);
  canvas1.drawString("がさや揉烏帽子もみえぼし", 0, 720);
  canvas1.drawString("が、もう二三人はありそう", 0, 780);
  canvas1.drawString("なものである。それが、こ", 0, 840);
  canvas1.drawString("の男のほかには誰もいない。", 0, 900);
  canvas1.drawString("何故かと云うと、この二三年", 0, 960);

  canvas1.pushCanvas(0, 0, UPDATE_MODE_GC16);
}

void loop()
{
}

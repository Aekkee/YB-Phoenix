# The Ultimate Guide to WRO Future Engineer 2022 [YB-Pheonix] ✨


![](https://lh3.googleusercontent.com/u/0/drive-viewer/AJc5JmS-gvzix8rqHiP9ptq7tHeZygsObiNOmIOgPZ77TDPFEsBTKvNW-LatH-ngLn_0nhACZ-FHElf1pMwIivX24kCyNMjfTw=w1920-h929)


<p align="center">
  <img src="https://ybrobot.club/image/YB%20Robot%20logo.png" width="200"/>
</p>
<p align="center">
<b>By Yothinburana School Robot Club</b>
</p>
<br><br><br><br>

## Our works (Youtube Links): 
Qualified round: https://youtu.be/Iuq2aRa-G8A

Final round: https://youtu.be/I5dHPB5TrM8


<br>


### This Github repository contains:

- Design process
- Crutial robot components
- In-depth program explaination
- Other links and references

<br><br><br><br>

# **Part 1 : Robot Designs** ✨

<br>

### **The Robot** 💻

<br>

Designing a robot is not easy. You will need to plan ahead about what you will use in your robot.

For WRO Future Engineer, it is mandatory that the robot uses one driving motor and one steering 
actuator of any type, and it is highly reccommended that your robot also have **a camera.** 📸

The robot’s dimensions **must not exceed 300x200 mm and 300 mm in height.**

The weight of the robot **must not exceed 1.5 kilograms.** ⚖️

<br>

## **Choosing components of our robot:**

Remember that the best of the components is just a small part of your success. It will depend on how you use such components to your advantages.

<br>

- **Driving Motor** ( Power Functions L-Motor )

![](https://www.lego.com/cdn/cs/set/assets/blt3289051a0e80fa54/88003.jpg?fit=bounds&format=jpg&quality=80&width=500&height=500&dpr=1)

A simple and fast motor made by **LEGO**. There are many alternatives when it comes to motors for a robot, but we chose this motor because of the ease of connecting this motor to the frame of our robot. We need to make sure that our robot does not break apart while running.

<br>

- **Ultrasonic Sensor** ( SEN0307 ) to measure the distance between the robot and the walls

<img src="https://media.digikey.com/Photos/DFRobot/SEN0307.jpg" width="400"/>

An incredible sensor that comes with **built-in temperature compensation**, which can greatly reduce measurement error caused by over high/low temperature. It adopts **analog voltage output**, and provides accurate distance measurement within **2-500cm** with 1cm resolution and **±1% accuracy.**

<br>

- **Servo** ( GEEKSERVO-270 ) one for **steering** our robot and another for rotating **the ultrasonic sensor**

<img src="https://cdn.shopify.com/s/files/1/0174/1800/products/Geekservo_1of3_37e262f7-5470-4184-8990-40ef2955fc43.jpg?v=1593189003"  width="400"/>

- **Compass or Gyro** - We use **CMPS-03** compass to determine the direction of our robot.

<img src="https://inex.co.th/home/wp-content/uploads/2020/07/cmps03.jpg"  width="200"/>

- **Camera** - We use **Pixy 2.1** for our robot because of its functionality along with the existing pre-made library by the developers

<img src="https://www.zagrosrobotics.com/images/pixy2_3.jpg"  width="200"/>

- **Microcontroller Board** - **Maker Nano RP2040**, the brain for our robot

<img src="https://circuitpython.org/assets/images/boards/large/cytron_maker_nano_rp2040.jpg"  width="400"/>

- **Custom-made PCB expansion board** (Made specifically for the WRO Competition)

<img src="https://scontent.fbkk12-3.fna.fbcdn.net/v/t1.15752-9/312543477_864323261402550_2361715707743165031_n.jpg?_nc_cat=102&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeGju0acivL3LPg1NlmJw5rpRxLs4MrNLuBHEuzgys0u4LFIHrDd4z6OHS7dHHK75xqp_KBudy6_cpprQu0Z7R7e&_nc_ohc=j5MAHyUpj9gAX-UmlOI&_nc_ht=scontent.fbkk12-3.fna&oh=03_AdQAZk8ulJzKZ_N_6Wscwp2P_Fpbmhr20Phe64shOJHqJQ&oe=639A841E"  width="400"/>
  
**Wire connections for our robot**

![](https://lh3.googleusercontent.com/fife/AAbDypBMpb49LbKQ5uKGLfBDmphj8Q8arFVbUlOLNF8VVuXZUzkWvl3eadt5nIXetApAGM7xuwYlJYdm-KfruJEWDW08ieDruFHPaADXrP7M5XFcIfTFgCtY1fjK248FAwB_7itTqeUqzz8pINb41MQSfPzSzkifoEEMkDSyi1I-xJGw0YoBDbfG9zFeddrwtirY0IhSuuieEyrTlboi465iIsCqC__VBJN0-RV1PZkTUowbddHRlyaFzzxbg7O-Jov3FQW7jEgIFs0O2N1yQPx4CO8iDaT0TOcZ1_F7_eemipeXO4S4E6m0oJfD1PPAM21phtAkt1eKt8yExGOCzG3ldnAfriJ87OFrO_T0MO6mjr4OHHut8QX6QlA9YFfd1lUWe9POO6wRtRw-sgNifQiTRhEBlmrgXWLpPbZ0hRhcZYgA7tPZLdf0NT4UTS3-fbQSNGOIUq_ymm8Gx5ijanCEv4of1LiZajwnGiM-FbypDGq1SEkXtfCRteScp8EkKMZRXxhc3aLF2WPfy5UFPwGRDMAdBydtPxS6vD59GdavwcT2wM0_KaMOVXi_bt4DuZG5uf1BWUjaZsJMuJi8ep2sVsNUydBfVH7GA_FGagEzsXjmVWXOPzN4mLbx8haLA8274SpNiXhLMwLUam78VUcSefPEwddz6qgcSfW9c38OUQM03DozOGG3lE8nlZVFuu34VbXgZ8JWC1oPFVYxpYdMX1uQuENEolRZLeBf9sLs4i6UjiRAc-Btg6yNIvgf6CE30h-MIxXZP_CzLSxrODLrGQ3JfhYhH6h9DbrDEqD1pzlYd6HwN8QLn2BRTaJ3SNkk-Tw5X4YlSjZ-BdXg5h5t8j5lQq5Bku3wTZZ7ko15zrIhn_KO2Khng5n6a3ZsXnzQ6rLfF4_KyWNc7id1gsK8KbAWzRpw2AFXCg7J0mUvOmT2wbMUgJLRstg56BeaUlR1xZEQj-dMW8avdAiY0MJnnNpAz7QgXOLF-1UgCnmjKFx5rBme2_4KOm02dMK3lPYj1iV_REC5tAvsLiW4PKRkK6pgRKA_UWmDZiGZTorhgJcVrHkbaeyVv7oI31QaOPY4ULHsYju2wQRvFyWVeWqs5aMI0TRtCV72LUWD1kFNwv89BkGQWG-RRzy5oaxuqUjjrEll-fXJ9713vTQudQbFeSJgInNSrL6URnIIbswHI6UHWtb6ngPBqpmc_I5vtKsSB0Nz8LublM7z5L1st0ipVBGiEdzOLmtNY2P5TjpzVuQp1BeVMTFz9hoh4Mw7k2N9WQ6MN5EnKXEihFJDayxoqXcQYlAfnT-nycc0X8_VMKgcp_BbtZDKjNSZLS-3P9kW6iJQZ-svLY-Kgk1fj6WakgY1gD_dJBEikCEsC6Xg3xRZ0m75TbM-XgiBCYJun125R1O8SiooYNDEDzBQkEclHLUtWslDrk6fyHvGTah7XUi6VBy-ZvxaCCGKSGZ5y7_hiDPAFMNbYElfjDyPHmzphBHIXzpD17WWDNppPShQ0lq32baZH7wJpz7RYXy8GUUJY3-pWqFe1nv2C6-V-6pPQYzPuNusvADoTesBf1jDZtpq0cXsnKuOVTBUcc7a3pai9Sk5pePf14ab34IXVvzUipNU9P8xd653gCYYeh9qnW9DJgX8KiSAKvAuFn17jcAXdeDG=w1920-h929)  


# **Part 2 : Programming**
 
## Setting up your Board and Arduino Software** 🤖
<br>
⚠️ **Please Note that** ⚠️
> We are using **Maker nano RP2040** from Cytron Technologies which would need a custom board library

<br>

For more information: [Arduino-pico Github]

### **Required Programs**

- **[Arduino IDE 2.0.1]** - For Programming your Maker nano RP2040
- **[Pixymon V2]** - For displaying and configuring your Pixy

### **Required Libraries**

To be able to communicate with the sensors, many libraries need to be downloaded and included in this project. The libraries that will need to be downloaded will depend on what sensors you use. Most of these library are very crutial for completing the **Qualification rounds** and **Final rounds**.

All the libraries we use can be found using the **Library Manager** in **Arduino IDE.**

```
// Adafruit TCS34725 Color Sensor
#include <ColorSensorTCS34725.h>
...

// Ultrasonic Sensor
#include <NewPing.h>
...


// Compass
#include <Wire.h>
...

// Servo (Ultrasonic and Steering)
#include <Servo.h>
...

// Neopixel LEDs
#include <Adafruit_NeoPixel.h>
...

// Pixy Camera
// #define UART
#include <Pixy2UART.h>
...
```

# **2. Programming** 💻
Finally we got to the interesting part ✨
Please, download our Arduino program, and use it as a reference, so you can better understand our explainations.

### **Part one:** Setup
- **Including Sensors libraries**  






- **void Set up1 ( communication between sensors and boards)**  
![](https://lh3.googleusercontent.com/fife/AAbDypDoBCUtBNHInyxUW6POKqjqlr32bJ9cwkqRGxk00nqvwL63Sdkmf8O42UpXM3SDPoTTlRFafiBpHbO5Z_WzKHs8AJyCZEET8uj4ZCkqxJmPGTmIcoX5jFx5EcKlSG5jsP-ajURQZcFy0Z73ABehQz7nHC_k6axkO5spbWNKHwhl_-W-Ilod-cl0yMyE8xcfw9FEG48FeVJzmMZp4tBVOWC7oQp160lBJDhU3JWDhCgUSYrY7bic2rFSxwLWcXaOITusW495xvUbUJOtJYyhCID7bZBZGh9qJo8QgmbEAzMOkxc82HNIfQdxDZRX_ET-BPs8GNcRzzoNTv5-I-dXERi4a--hMowZuURNGpiToD551Y5pkKEM2LgCATLER89rGtqsNXA-hTF10Skce3NT6wQNx31Q09KX81Vx5qrk0rh3h-clotYQbmWl88O_a9xtrRPi49iw8sBXZkLtpTNqjLlmrCE2Tcw_99yy_lSXvepvBg0Y1WxCVT2q3cqK9YIHluQWcEpKfAJhdW1PtN_8s7MFNCXvXVYIhNfnfnaCHtPiQ6gqh9QREUdwStOLXCVdbQSR5dB-tHhA8zHqKmU9rQxQR0knBqW7JgBfXUKOqL0m4oH_OR6jhFHuET0-02Is0KUP24JkN9JnXwzx4b-YwfElrQ31ooqEhaWkrXkfk5QK9ckMsd7twdUWZLyvTkBCEYZhcJNXnROVhbp0PXUunsViZo1KkR7Q6Sqwsk8pdFBCfjaYiNtQYJUGnNCZCGpZGU5Ag3EmielZoYudvvqDa8W1dlYgnXsHV0sArkdxDD8UISmvHolG4Yn6z8dsBjehODsbURmsH46LwjiwXdrunSGYZypEspGLcneqZEZTB5HZLUYZCviR7LbzMWq0kJ_hra5LtEdWohKD9BbNo9xbFXwRN-Cb4L_ZMe7DgVqpx2RfDD5xv5GEXUTUdiL-r-S7dT3yOsVBKD9KqqfnUBblxLUFHOMrjJAiq_JgAYJSgz0nNJdDCBgLjLrdrd_pqCyEz0KswlnEueNe1wW-YtrmHR56SW-plKxdMLlMydIPRS8nuuArnKCphs1LBMgjKNLxUsY8JtIFKHVtS5_cV6fop0li7y1T8XjNkO9xt3i3iJkE5xdTuzLqfW-J6qqvPYOioAFnQtgKVncl3Fctb1sa_GnTLWGm3srhLEejVHuVSLreOipIc6EIhqGsQpLiUh_Hw3uiVV5OvCgH3aQXcOfgN1UoB_ddvDl1RSSJjx4nPBl8EYdzVvaojoKJz8BZPjY7C0TCtyQ3qnLMOMMdfewDnQCV2Y0BEKo9vHdFQ7MXprZpZMWfObC7Sc1PD0UO5XAJd4l8-IGQ3JAS79B4nAle7veDB04CATh-R56RTE-soTTNS6n7NQLb9PKyXjuaum4tJZxEwsfNXSRLjUzqaZqoL2G6g8KoyOgl2WFrtuXi1diAHEVdU30YeAzw=w1920-h929)

### **Part two:** Block detection and Robot steering
- **Color detection using Pixy**  
![](https://lh3.googleusercontent.com/fife/AAbDypDo2WOmB2DtCV5U8sR4sGLe_OFGH4g9Vg7N4PIIYmCPscsrt0QWxGzkq1nmktyN6a8tPilJGx2e8ksjzy-kOQZRomiHENlKFdOPSClxG0ji696qcPnnTdN3SCtP6yFS2niVHpKZSYS0-PfKXZnI3IZ4TsLJC26IfubMpHjG0J-LQozy_VQPc_3IyM43CRF-H1XrNawwkRkqSKkJAOexdxCXXgj0H1vS1GH3qMtuEvJQAwWDXIcYUUbWbPcVcRmqXMKprfKYvwdCz9B9M18OT90eL_fCjGsJnclHvo6hH1xZdkSiWx_BDGpVckKCB23jkJ6HzUti2jblc9W4fXOF5Bj600q0s1cKVLitw-ooEQiXZYtWwTEvYUMUBNeZkCpfcusGziLvWIxjGOFiM_qWQVozMCKJDYJRgadnS9ehpnJA1dJ7Z90D5DcEZq0IdSQi9bbfPN_zAFN6V2tuhWcg8AE8YCqzIVLWe0LXynoikXNcG3F6il3eFXjw_FrJ541NuC0CEj9Pb3I9h9N-vsGaMYhPDK0WoCcXfkECT992a39UIKogojWvGtFITEV2fUd1OFGTM5LKIT96l4fYjMI3CbLvFp-c_ppBd5s1fiNo8P1L-Lda13zSNlYX1tImqCwCcc2lslZkb33VP1a5hzoHPET12PgcSOJ0NKrvdYRrbk7oYwwqw8wOaJ51uvs7n6WAdKFvwz3kzkkzwrOo6mkrQHPv5xSI5xX0YjDZjjYum9j1c0WYY4N62qGaqFE5Khn4-aWThTGx4Td-a0kxc1oRL3vtm9gxusVE5pc1EsAzZZlDDXr-DtEgwcZK85i-H4UFqzLapvuL14NF5BPZsOhQptoLUrbOGpJM9qWZ4kt_5SkmJrGEhO8dDRLQAIDrII_tU36ixRHor2Ws_R7uAAvgf9I-h9FRDUYvsaKfPzzWP3iYiEk5wOFtwhG2lU-vMPT0iSa7Ud1B6ERfFfC8_evQkasGmoMwHrlA-tKpc9tQ_PRk0zrCaJycSmLBtso-CtRisgshSc275nBMujRmHK-sSHkp0t6jgutQj_AsKz8mW1qmxrlFQG0sCQcy1aZpCTQkhwn6yhKF0sr1rCRSwkGlTRwLgbvHwHJJi9USVwMw9SZLiCUGx36YLu3g0tIOfGs64ru7karuYCPvpYgxwOFPeOClx0lwb1IYHxgnl4wL0XR8GlHu9H9JHVtG94IQv2IRPZKnzIFXtB-bUtw9iH2tdtJZQofdlgSNJBWeoa8a2dTb4hiBOnzbodLbTfN6Ph_uEUgprxvFzU6r5SeFvc3-xftfaISeiOI5v1xZHPSy4Ra-u2szIeM6dxFVAi2dadQjPNvjamKrGHzwlXKsAGzP_8VBOkjXXKtFOwy64ObOETuTtPme3JHZX9-HTeoK8qyoY-_XGLrhSED-nop7iuTj15hDSF51SllMWsn2iW2CDkuaXUUaKnAvskba=w1920-h929)
Basically, this part of the program identify which color the Pixy finds. The instructions are as follows:
    - **Adjust robot's path using color signature**  
    ![](https://lh3.googleusercontent.com/fife/AAbDypDAMWveU2Jn_tNErXpLFKThiTEFp8UaaCS-FhQRa7MCt7lQyf8qnEGoLuunH8VuOOTt_DcB_7IdZC9x-ejX6VenEZGjx1oavyO-VwAok2_8s6zkEdiX2gOoWBke9DC869z4hHrWAhpukleDhuvWBE5gWe_RNJm43PDpA9_DKEa5bG2nA8Q8idtJ__ueqJLU7ZBclE2RU5RHXlXnThLackJVZwJOrNsbBUO7VAufXMKLAFmB0YmXLoWJzuTjySnlEWRETLPZEXSwOGPz6xHHzOtCvPMtuf2gwOdjCcOdn2rK0f7wJ7A4TN1dNuwCSa3ChItLWd-QZd_v8x1_UYM9B8AvL94_9azILVtHN7C6bZvupc9Khel-0adNJ3sW1_39QNMg4mJNHP-dgiPJczYF1brgUaowiHqDQB2mBgn3yA7GYDOnVsOxfX6pD3fkCn2b6qdx9Cr85gn3_E0jucaILVlGVRGmst1WDFgj701Kg4A6vTDrvHvbfp3J_04I3I_JYnMp7xmz0wE8vGwbt9cRW4ExHOHRp08ZtXxozwujPew6Q1iQfe_0Q4uMgs0PbKqNmporWKZGD6M-ZZ7EQd-L_ocwnwU1Hso_-Pqli30z1UTXbHDrH4WjfCaG5L83G2uqKRJWZoGhSWW3NtqEG-PCvxkonjc4_m171XmkP0mK32UuwGKwR1Y2Vbs9tAQ2C0667fa11gxauxt-LBEi5Z71UZqp8aCPkLDERBDAj8DD3_TnWiPLtZwYWttuBgo-bshrLWALpAlbdsIXlJn_NzPmUUvvhHJX59H8xm9SnHt6WuEGhMLLvtjRYoRQCXVWmCoPaXk3QY3gdzPtatx_L5lpGexl4PEqGmRElTPuqzwVNMuzz1rUa73Y9oGUkGtDgNSnUWJ7EP23l13it03Jzfe9vw9A5G7mwGihuzCRibjPNAhGMUnQrCxmPKfJZp5oOpnl_B56fF05rhvC1TS9DQO70VvUNnIwhjz_GPRuFeKWkKg_yhrcxYoje1HzMQQmqtnVSz755WyvUmyvoiAZj9ERAK8AQyQgyiEWtQUwAMqnZxEWWETMevwtsw9fK5G9T_QcPwfek5A5CskUbBCKisFBYH8O_YJ_qu4KKVeN7S-ghYMJ89DcHuuSa7P_2Uahocgmrs-q_64d2_S-NrMKr44XSv4mbgHYnlrrVhqXRTJBtt3M2_J9QBref78vWLQs7ZIVJSgrMtDRfjr9lSJ44eJaozfFMBqrMW8_VYz9xjC_Syndv2md_faKXSoWIiDhZGhSJnGpJm_eDvf_qR4Yz8z2BkLnPHc7auBxQpLlwff4w8c6C_WknG90zx7YguItm975BsFHf8QOaShso8oVg2banqH9DHAcVFIBLi35ZJyoZSIx4-Y4q9eJfMPPuvGbkuPVkNuTfVhFlrgvDVtMEgIB-zrIFKpyWofqXcZQ7sAieEZfaQ-dmC0LDQox=w1920-h929)  
    If color is **Red** then **Shift the robot to the right of the block**  
    If color is **Green** then **Shift the robot to the left of the block**  
    ![](https://lh3.googleusercontent.com/fife/AAbDypD4QLQ8vNnnWWcWHOAoVVmfWXYSTS6NW5RJBFBDBHkialNd3rFpNd5DHWMveuq5Bj2PTGkPQn3MXbVjopW1ivrxxkPY_Fma1_2BDrIZE0OYaydA4m9A4oUFFg7Cs7ti6pVOPsIT1iTssgSDsNTJpRzy8ZrqqLNirwfhiTWJ3-kMDtYJsSdTFkzK5qM4tTXqHZPMgcJ9pfgGp_RActZWMK4Yb2BPhjMp1isaoqh-D-Lp5mfR2GOw_E4b8posh582Qt46hLgye8F1iXg4AifJNGarFY-IBl-PIsj4rojR6GkTLBqP5Au2g-xvXIggo9ucqzDUzxTrEfr1NuwqQrHSjSbyNdZV3fMF2uuGo0FGNYLixeTjjI7Yyc5sxQUKNxYftEisvkEzU_0vQnxpoQ_WoOxh38b7Y9Z-yScYDL7sT2rjOkNSrIU6toVIkM1Jc_qHZ0jqFxTlPwdWmfRuqUQzn-6fB1uLpZWJX0WCkFFOjD124Yn5mClOkCiCIKzIYp9m7X2oJmNFPI-ppxpbUIgnajJh6kMcqR0BAyOVzgqNXPWW46jKNkqc69VlO5qGVWjSQpzbB4CmoiZymAxS0ipOKXHWtTQ8eYJPmfKizEzeCvbKsYoWbAWGTvoHmBEVcMYTu6r1x05N026V9edZtzOEzzUWQCg1oyRfsYt3WiA1ib5hI1bpa_3n9Sw7KXvS6w7uGodpZN1uIuayGiXq5ND-9hBdacSX_yCS4anA2Rm3PKQu_FWpMqnyf0SM6aO4uITjkYUhkzSRL5ZPzvqd8RivFWpLYPhVWrS8Mg0NTLNieNM76Cn05nG_jzCRjto4AUhHce4PR66uJujsX-5Gb6hvZ-9-lzZmBmqBvJNb06XxSZa2nfi5l2TNvA4IiEqQjAcEn1zwQ551cyXUYh1f-H2AfdAUw6s1Odx_sUPRff3cRA1l718penfA714C1oujm3mpotuEwpvcJzVdvPRAJLh9wdB5DZ7Hi370q6weZugfD9jRoadyBoTWY46Rzx-8eA3ctifbTduXMZVJlC7SO_kInBtq_yXFr9LJAaynESk6QJQ7eqpjmAZ5YKXRkwwOxzH-QoDuaO_xs9U-oBiLGEkV2_V_4WBKk3G_nBaoc-Q_hcC2Mh6wUSv71VzVLloOdrc9Aldyh40z_xdz53D7P-aB1_wRbZKmR5adQ_CsFg2g-ERXwkAh13ZoDWr5OKZ64apjeF1kVHQi4VtLbKem1HPGyjLs2iM4-N1gigZccL7RQOFIKw_eS8YZ9jJ3lTGV3ZZNHkV1H6X-499LC5XBJYRbe1FmvvhQzREH-K2dyl_d3Sz1ZhSTC-5oCVPtG5Pm-9NPbjix9k4x1zY02p4o3OiOYCwRqEDzYI8MGE0-wXflDKz9XvWMPJXVdwP7HetV9BnyQ3bv1wjBHTT9ky0b3iZlEOu9Hl0fckhn9O26YUXeP1FQz46pNcNHni1U=w1920-h929)
To put it simple, we are using the **quadratic bezier curve formula** to determine the direction of the robot.

        **But what is a Bezier Curve?**
        > **Bezier Curve** is a parametric curve used in computer graphics and related fields. A set of discrete "control points" defines a smooth, continuous curve by means of a formula. Usually the curve is intended to approximate a real-world shape that otherwise has no mathematical representation or whose representation is unknown or too complicated.  
        
        > **More information about Bezier Curve: [Wikipedia - Bezier Curve] ✨**

        **📌 In our case, we have 4 control points 📌**

        The formula is as follows:  
![](https://lh3.googleusercontent.com/fife/AAbDypATYAYSVzyFyzcO9Y8Lw_bHWmurQLr3pwpLvbIba9qZj3SMmVark8kveDfTkpM0Uf40ed9B-4JJlOhpJCVH2EHxdFsrdnev0wNIUWe1pR4FZqAfuLhohlUk9lp8ksSwk-sK8PKWF-eFMgkgQL8HKgkbyX3mJgutXqkWrM1eJduxb0GDqeI0fCA06AmzZ1VpcBgqbxnmeuleWsZB-bd_XEnwlsjA5Elx62T0COl3_YSFGGRfF4DjY3WB-1woPX1MISYOArpeKmPfN4L1K6ASynj-UgLoo4VIckdjWJk38nLL6tV6E2Gqj7tuP3GuU6jIUBVZvg9QQguSWdrF24HSlEnLNNNi9Hk43LD8xRzX2XVsJm6oQpxgc_JA76LGuobwMjao2fLC_ceE1myFqonnFi8zTOZkNj3JdWclLNnQFP43OI3c-DYtTDQ3VNxX1ZoSHEPJHtBMuxhRgUDBy_u4JyvY9uyp88HRUDBakUzmAenHskr_svIXAAR4bqS2wFgF_tb9IodqzWAYgyV6H7yWt99QNqQKzi5EKd3ooumy_4-IcqRen8VVtdk20TTxkrmwbdnugz0ZLP-eBumhNgbJS4ywaBpqcrcqJMUp3M9QBIMLkzymYaH21Qiz6vpZUnHwae0RC0Yef4hz1hyFXgJRuT_a7usZC2lLzPIHbfm83X-rmJ3lgzRLP0uZ26AWKPHQFT_3h8ywO8iOVuPIodtqbC5JzqUxoh0cFR-BcOr11Vmm7pXDJKNSePdPfSxhkUm7KlvESAfwLnSdUU8GjBiLK84-yJi2ZQZBtGCF_FiclVGG0R5DsLVm9jZZwKod-1B9DzY3-oLIOf_cUx-BUK5pKidkApm_CC60TW78m3VPbg4NK2XxQIsZE854KNUiJ802wvMHjFNE15nMOdGrD4dYLB8aI_yZjnlhc5nDbqSFfrxKl_j4LoBwGt7OiuS8bN7eCZuwb6tJfYcArXFS82jnHV01aHAWUT6bjam44Hka65BWhpiPWGucAWd3iuDPHkU_gMOqaSvvJno8oHJiwhhJl0CPRhSNPDIo2t8Lm28r9mL0mEevZ4mTSmvPzyZtxFq22xu1uPWgdqytNMWwLQ9fvrtHtv4-yJaOKJ8VHXEPkAaKwWbYUDgVGtXowZezvrm0XLnPlo9VrG-MkyJS2H-VAxUmLnkKtbAuox29bPWUd0clILLFuHTkWXKscbAsgg_vPLkCslfbP5zA13PZ0z6vhg9NLENwRDGhAQ0A5Rd9SOWBVaOGA7wfqfLFFTtKgwk-2s5kJeSZjdqi2lKxF_GjNfd5_oPu3n0LorW7nyF-cHIiIy6wnjd1sbeQQDoyQvTNqNFAP8ufETBiNdZxSc2Lt3FuNdI7r9m6LIZ0Q7keoY9jl_Ro7Z7uvTsgvTkG7L-Ei5WdZzXDuRWY29VUsTMyprx_9pxthUK8f2GXLctmLCv3QZMpZ7rzWNVR=w400)
        > After we get the **X and Y coordinate** that the robot needs to travel to, we'll **convert that to degrees for the steering wheel motor** by using the following program:  
        
        ![](https://lh3.googleusercontent.com/fife/AAbDypAHzC5M0sBhdJrIlU6XGnXttiSh6ecebvcLrEsPlhhEmdPpX6r7i-wGedJ7vKiie4GmZrbdCkSyfcnlYBCvb7sVNiamjRPEgi-3l1EJ_s702CBq9FDJccZusXEAw-XAo8Gmly54wDM63cm9nDp2qU2lWtf7WZw-OnJ9eLs49cj0Yrx1pV__OIjz14KMSqcNk6jhShJlGOYnyp_dxu3z1QFr_2AbnDOwRcmJvq5Gjpedzu2fnSoOjbP1VCFCApJz-ZLpjBEpw_qfcVsBqT6rw1EGRbV-xOeAPixLnvZ86ytnV5NJd7ZVObfLNNmmSrk9Tr5ETJjbbFrQmBTDdvBAS5tjjBgvucaqEWWOSep1UJ1RpGKLZh1OAcSlDvM4L7huE2GkvIGv8W8koQTK1FRo0wCpXypQWgpFSXZ-4MeoRMiYsqtIG4lzw60tSOE8w6IlYLrZPJw8is4_2v2tkVbgak8lJ2_tYSGkMnyT4UCRbKVHvAOauuVaslgTcsIfysVpK23j-2bQ-im2tWI5NGydNhVFHV5j6GQCgaqoE4Dcbl5_lrzHaqs4l7h3DG9julXFZLPt_Luo2D0iOrNnwU8YYT6CtBuvQmMUmv1m24anlrzQ9VwwZsu_-_cqvWAnPwoKoKkzmO1B4s8ISPmbnhLiqK27qvUGfSQ-8jjcXw-YOD3Hp0LQ4B5YYMWtD5S2bTbDJUwhGVa7SShPU4IPFIk7S_5nhrS6Y87wUcCsgPF-vjfLtK3ViPa0wOnXbMnfhO-PxKgtBg3KpgaIYyFXHMdLiTuey3jGOeXs1k1DxGqKPtqBelrKhDyHOg4Ab1JH2oMztnwCBQKReWYAAfyv70V3zYwjJTzo9BqgJfg9NRHp8Ch6CE66yeA6u4n-sUzRwDHoXuB7YWwYZ3El_s3XVXfyHKia-L2N7rTZzcPpQgFRQrVLEeHMcb57Zd7zeBpeHsptVMAgzriky29bS2o_owtREuMeODWDlnqU0bdUqvJVEIwNqA3Yh68vcGNKgIBbU_VRPJtbb6PJNILPV18K5-voB3NxTui2gUK5Tzjf0K3ZXYd31jqh3CbDhXk14SUMMt9Ik5rSM0k-40ylbn7-BmKg5L6ftc7LD6puoejg5kLoMQANXobl8k5etmNJpyZo9bwlocDcJJ82DODOsM9s3ymf8pi6UPk1K5S3jyzP6wiECiC_QFc_Nsfo148J_gnlUPTOf0b9KUlYYNP1rWx7yc1wTJgkyZcq8ak6ZtHIduZxwCAp-D4Nfg6mnp2DatmN_tcIzf-lcu_JIiaB4nn4iNVwxaTt0X8_XqcMvxE1MJt1WSL0GmriEBNjucepWVi4i--2K_T2MB54ZEcxc--5knJwFaq-VtDRQBIuHRjZ8peRzxPWXqXvw7ftQBLY48lSG4ug0lTEKAbPxB4wO6d-C1HsYAiCUJ3PoQLf_BVZl8oW3olb6husVZKpPoYB=w1920-h929)
    - Adjust robot’s direction by 90 degrees after reaching the turning area  
    ![](https://lh3.googleusercontent.com/fife/AAbDypAqPszHc3wmX25lIkUjvuigtjvkh02RBT9zwXJ_AV8qzvOGWG_Vpqs71u0O5IG7VIEkLieK5CH3fCuK2qOO1kZW4_OymK612jlIEYURUE1EoBGEnZ_VWWkTDZ9L2JV4Yi64MbYIPA8rb0eo4gtX9006skAkd7r_WP3ByWZ5Ov1sL_0QST7tyAh39Xvt8XKHR6lCnhuq0hWIPzXrpZrn0cZx7w_aXc4uylK35Y_G-y_TTnK-VyyEL_aAUqSBmeIIHBtw2PxuIK7OK7UOKzeCBeZodDBb91cWNYPwWcUjs0U6YYSI1Hi1rLKNypLz5HMrrGJJslMo8N1A-TSMKetwX-BZYW5EhuZuxCEkUbGZL1D_XkSQX1cr1ykuZoQjx6XMNM0Ja3VvYq2CP9Lw93o0nqI38m0sVUyzaC6pxP8ux6u7dHol36FvfXifV-unuHgVZjqNdk9XQUq3n1NTOiFxYmSl2QU42IS8TFCkC7IDGSBJngsuyoLyyU8UcA1MlBvxYXtCbXPaRiCTSugXbeTAtGc-4mDuVL664UZbhyTEkS6SdyTSK0S9A96GeWzzF8WLh-JfEZRGOPdx4mZ5pQ2QZ8Nz9S7WDfUqt6uVXirNn6VhYTckR9WZwQjcSYUEvVq5AIgD6UTRn0qpRvRMtSdOWy9qi3AW8LjvPSXNgNekXEbi9bDVTP4dzW30LxjiKvELCJm0p8rqTWLMJYpyyY_uPRzmm--zCrJhrndOg3Qn0Ksa9rd_7TklSCgqoWbwOUubX2temsStLnMVd8gbqmeR3ql-DntrKqne-jUuQfNWaYArLjuBe9PTX3sDznW1Lx1e-HA20PlQl1gVeD-MJFSDxlxp5o4HUIB2iqIhJ1hpVXopBImKBFAzvPdYFL8kpLqFW642bUflv-KXuSPN-OySN1llIgdH40NIEy9icOiEyneekyC-9y_wV8_HepDoiB0xPGhvPv0FOWhWb2hNft4NL1qZpjcEiWCgFSHELNHgPoiHhPoY6gKzQn_vk3KTuHBXLo8o2j7dSzj9_UFJ8ZgMDY_V7uY7u30m7QuRTzfA_MCerinExTCT4XR_Ob3YV_GaIsSOQyFY56ZIRDOauxvvYSdha1Anl31XF__p9NfBPKKsNF3JWj0N99w7CpU-bcPoIC5sZvFg3owh58A_slXm1W90G8tfGpcdwGm8iQ8I-giCgmvvHBIU8l7I5wCdpoRIx5UhDA9apowx0q0DU_mlpeqXet0CubElraGL6utRh45qn8z2g7Ly4hmwaFJJcGgrBVx_BxUoOS373x3szc_BmlFYmwW5sQkUtf62RadwEWJCSiFf-6usf33Ckj0nDc5-8_wKfUxSX8qTwa69x7xKWlQGzgOzDiQFFax8zZp5dtnZDCAKc5fH7nUsq8kbwCYS3oHW5mQKZbMbCg9tV3zdWWpIEHHxt5O4qZtT6yUuXjfSqEwz-rAmK73j=w1920-h929)  
    If color is **Blue** then **Adjust the robot's default direction by 90 degrees**  
    ![](https://lh3.googleusercontent.com/fife/AAbDypDWXd5mWcKKQ-gScPsW1K7Q_ZRWQ9TaznbvolquV0dytodjZB6YHIp6K6jnizyMi9ScjEapgEU8xmqhEPYtdyP9QoAFFB_UfUe0PTkm0Pn3gBY1REboFXnHOX_jeD5RSfwBmjylRb2U9AbZ8XvW3_rQ9DhOBE4VaP6c2qBPr62Wzp3vvVlIcEmgZh71AxbfghpygG2cs4b0Au_DANJhCNdqIH22HqBVICwVykqXuxPUJeiOhXQ1rJxE5zOizNjdgVZHs9kRunedwnIEAlUldIbWAcslUXcTH0ZI_qB7SmxjjLA5UCuSfnj57wD-50idJhSGPsBS5w9qmi-itLxVXPsS3M4NjozBWF7GS4jlOvhup-wpLOfIQ5yi9xWPXxASXVUL6Qbyoea8aReVkAkiFf-4ieG5dabRwjaGibE0Quaj3wAostdK88pNVO-KUgb8nM9DSKHxUM3N09lndo-5VR2UJ1s7YvjZpa4HJMJJTe3wp41mUJyDbbWtgeCY8VoIhJ_8U7Eq6p-32uqU-kh1W2yiCCKJSgdovpDf9hNDRJFUDjfh4Qio9YGsZYgbOppjhWU4XfDL3pvd4HKa_FH0xFNJH2jmhAChpBmMF3zk_B6VK4rxajGXTZNB6GwGLXdOc-cAU9Vd55d1NWyjVXArDtPEwNOldHhTNNuYOiu02Rd3TGHh8fjVI_mruOAOe621JtOPXjHUMcwkniikUKbvCMgoge5NlBBKkSL1e7UcYTkoof6aCGwReU-hQlA7TYf4doTMsH-LJXvb8E74JKiyaaghOHmhdfK9KOHmiJSTPlFsYY_HjqNM9gtcdajxfXrtq9aikmquQ3TN6Hh4wnlePiUgoJxTBgP3r8vtXzOqlAnmiAs6O_mt65O_tzatAd5dfN2tOft-O1EkAVmdKbJ1tSDb3RtKnzZ_DbAAT0CUDcsXQiJYxgMvccLqMHHI5VKTLH-IAUNtkUhv0k0MheeGl-gmibaQtQNWmT7ewyvJICi10K_IxDAEE4CIkg3f5yP0cKFUIyBD2DXwZq9jcRwP3VXnJK3gJQ-v3SK_iTOnFR9SVuCsDtm1nDI-4OViVXFglTu5NKf2meqDNagE9TOm_ZXBKROZLTAnTtcKWvmQufGiWolrZB3o7c71zq-q-bd0C-U-4059XYjUOkRUnrIjVvv1YhsDqW0mMOHZxT7SzXkm_05_n0XcxYG3HLQjSBikd6R7lTThwdIdkp7m4cxs5a2G9ePVXsjxb4iO1G8W7NCAbQJy5oC4iv8eBQAZSjaXCgQCsNmEY7QdWraVyWpxRvsXuQqN_udjVMhCHX-RGbymm2RAXRGEg9oJ97MiekGoCFruDiWbJnfZF6PcRrFcwaDM6XN2_c5_3e1frFlPajyhROrw2nm6560ngFF5wg1xP1DT9HDLmXl21LcC17VehUwKFto7OfvUPYhO3byIqAQ2uNx9VXMBxPGL=w1920-h929)

### **Part Three:** Critical positions detection
> This part of the program is for **detecting undesired headings of the robot** caused by camera's blocks positions errors, equation errors, etc. 

##### 🟡 A little suggestion from our perspective, 
## we do highly suggest you to ⚠️ **never create a safety critical system** ⚠️ that have a single point of failure. 🍌
We can never rely on the programs we create, so just in case any error occurs, this program would help.

#
#
# 🟢 **[Detection 1]:** Near-hit detection
#### Using the height of the signatures detected by Pixy camera, and the height of the blocks which is 10 centimeter in real life as a reference, **we can calculate the distance between the camera and the blocks!**

> **Formula for calculating the distance of an object:** distance = size_obj * focal_length / size_obj_on_sensor

The program are as follows:  
![](https://lh3.googleusercontent.com/fife/AAbDypCjLyQjF2vqpZjaAAG-T0slBqm0HV24ctHKi_UvyoXKyNPbJK6ab1D-ZnFg1ww3Nec48ieyfoIoRNK_Yg1p1w6CH5ynffmCxAasNZwluHsmaNQroIheo3PfHd-noEtavGUpYN1v30fHbZ5cHCS_ukiVD4rg_UATtC8AYMS3MH9WkrLyjXxqwFCiuz3mLYXT5qpjySjxGjXSKqbBGNpBwPqBol3CXiJeBHI4fRDtl7XactvdEehotWX-Lgvq_Y_0qs-oiZqyR7Mth4P7LjIiM5_lDrKoiDMDi8O460W-lN9bMJ-LU5oEz_-VSsPU1PmwV7TfOJ0MGAYE4Mtea9zV8mnqEZT7lfNFDWS4WdKBN7z-kRrx3FvgJhQibR07WjaiRgsTZImqWTni60XdMgX4uAvjc5Z4aSKw-mbuhlzPQOChtGrtjSnM7UHfVHzkAmIJYw-ZHW10b5l4ePMX-L6ZYwdcCSFKARO5HrTG1JVTIgDHukxghCmNEeDh2bsH1EPYqAIAsWlBdp6JcJe9fJIe_QwZCbn7L9reIdWwsXcriwZeaKn7oPXe7xOWzF1GWbLpu1BtNwT3KNuxXJbP6r27z6oHEAZV0FxwFyaDGKKlaLJW_rzoYRQgU_NhbHhUsze0Eg0SBkRfrmrly8u5S215gMdE6dG-fbsSgwU2udvvptw6fwHUy8x3OZo6sEogXGgE1RSD9WTVa7OBwxAalrDh_CS5kvPQbiSmjBGn_7pZksNFCsrH9l5GMDogNvnHn7LOHbFXZvwCgS8gAeBjdbNDvPNoYMxRDgp2-3WAkGE-jQBqTmH3JOBDZe1wDN44HtxgiCZHTdLbycC8xQYK_pi2cR5oi5SVgYkG08o3ThIa7zcD9ROn-AC7QIIUCK5hDRjRgpTza6GMOdp6L0rsbMDSY7kFXrZY8VMDKbYadhG8ErLo6Vb8drBxAoUNwlxD90NgVs0G8k7sfanUZIjH3YFpZ_fwBHRob2RA3eiZxnk9fq6Dy1AsiDT_jdJ-Djv-VKO26M2Wkf9T2nmyvds2UZN1_lbFBrbb52Z9BDTFp_wRFophDWHpPoim_yAde_n6whOY3HSa4k02Sm2U7-pVCk1r5Nm1TUp1CvSaVL6K5uXo-W9y8netewmb0x5wYjKRCAENAEc7hnmkXygPx8yPtrG-JVaKuHBCbFdWBbSlkY2yvwsaWuZ90PXucGvXpEbAQuXKZiV9uZAYgTTbsAA1MStcCtiIb7-M-KnL_5YPZSAjhlbB4-qv7XobX7U2yn8g5t3NcWetwECBWrv1um8mIPwcrZR071Me5iLMhfvAImH0FlbtsEgF8tJiTnhh5ow1Gl4LQzezN3Yhqg63DOTP2IBxyr-xK1AUH82JhAPE-A2DhAbRU2_zOpFiOGAH7e8FzLKk6HvDoLN-PhU29UXRewhJTB876Y8alQC8PltQvCuHa_EcFyQQwQp7xhLn=w800)
##### If the robot detect that it will hit a wall or a block,
#### **the robot will drive in reverse.** ◀️

#
#
# 🟢 **[Detection 2]:** Backup steering
#### This program adjusts the heading of the robot by using values from Pixy camera and Ultrasonic sensors on both side of the robot to **add or subtract the heading degree after the bezier calculation.**  
![](https://lh3.googleusercontent.com/fife/AAbDypDV3Rtvpgkvh6gzzoqJ7U51JMFcOq5YxxtGYS0TlrxSY1K6V_JZgZnD2zn65zdZEs3bwnZTrf989OlazfbahByidTy8rnCBnAsqU0yjdOSmdzYOqjEByyz8x_vI2D-SXbchzBv2sPnOQ8PDQ-Skz3QDn4sGj-JA05y5VN1b2ufJxsiSZ7jB695StLTRe2yVA7TZPiHkKm2CiMzn_Z95EK8Hz3GPpy3v_dBD9mT8c5db6arAEAZ9O8ld5OjPAbJ5_HcHOxJYEQo97-D72xpgwGO4WosIcYGJAWgoxnsV0P62DDcFwuhm_ewBl8bVb_ybqO19M7LHqpuT7hz6bBaz5_oxoJUG0U8Y3xtjO843aev-Gf1vIyN0MOBXEjzACRR51t5xjVl8CIB1KL-2UhQ5Z5tb9prcru0yjLLg7RGDVoYmvnqW6g4YMXNshoXx_DvXnUgak7Kqyo2D-bMhjqmKgCG35cBMXeyxjdJog4NpYAjT3HDCJSNmakQIbEIEHh-UeaX1Yw3k8_93y-S5rJfhbAxg5bG4u7kTqH0pZO5ncXJ22esNX-FJtPc9tAuDKsneZdVh2cszcn7DiKIFy9CxwQIjlRxXStlhTDQU7udbhF9S_4g30WzMC2VsGIXB_qHOzqCLAIIDloQH1QpDAGwjNhXJcyr_b6sIQw-nmF4ZK0DFU7SCBymTuvrylay0N0EkK2sCxIi1olcb4TnKj--RAAs3azIPq_eWxnL1ty7shhwRM_cfgp0QixUCAiqQgZBamBf6s7ffwCehtiE_-hekQisfOi4GBNTd6sKfXhX7oTW4IkKAGkX7koVZYXN8vPQtYWNS0rT1QSZuRresreSrsHsIVQKhTsaCh521sWOfLnjMCVzCMsbZrOkMUiY2twjEkXsl1TSKSGiNCOEnZ_C9852lCEUR6LJxBTnE6QDj-pxCpGsBS8bQ8bPqNYy_c4-c0ktqwsOX7DRfnKO_jWFBHpcpy88fSQAJnAJ20y8QV04L60Exh3XbKcJ7onY4Smldy89lmXpNrCwzXzm1TYDEkCgRtplVFUtr52uZ2kCVOITHu2pcXfRlt8L686-zFEAtA10MoYkB2JDLiQCfxmmnnXmbSPECzxEHg_vWE0BZ54JRR-3ZAaVXpHmHXXkrOU-H_Gyexc-6IaxzO6zDoncVwIfQafSfw2jzzKNgmrnWTxvjGD13JJmPIbDTtJt4lDg5SVjWZ2iHUhmSpLQKIr_6ilKsmDBZEKQ3iufsh1yJ8puwVLRjenEiinT1HTZRluOmFynKxLgJKi7zxMB5AsGOEGOntxK2-tzNEFe3EWXw44myTRb2BOc_NFZRbv2ykuY_GE33GA-6QY0KfdX3Z4OmAdxLCttZhA1T480eNOuPEXOGkvh3OHbz4nfHOUVIy0V-u0fdlVxI-TuQpgzvYl0nmuJ9DaW7cEridvHCPhcA8VRJhvDZ1kc4keGM=w1920-h929)

### **Part Four:** More
The programs in this part is optional and have little effect on the game.
- **Camera test**
Test if the camera is connected to the EV3 MINDSTORM port  
![](https://lh3.googleusercontent.com/fife/AAbDypAMXlgUzxccWHEoJ7KWykB7f46ujeOkY6n4Qe4_v1R4l5G3kUDCIg8IgOFlzirzIxJD7mtJjygEHpQGzEgMt2Sz-Fjoqggl1YK8VXD_W-1kpyogWZsbo4bqEQnVNKLQVOlbb4GrTMSvDHMYkYfhljy54FCfK2clQfKymtbl1GJJScy7TbPjXv4pDlxBh24FABfNLH0oG9BpC12ZOT_h3lHzbjFkJ6vcctaBCGms-nwfD5AGurTOHP1yr9CNwyZ7OjixmpBN7kytrbul9P-cJfjwZcuwStPyrcFJCOLwsU9KdnhpoAx13dYyS4zW0I_btgaoSXO9vuo2MS0oAy7_ee3PD5U6b_yYaRZ-CLK-i2UcKdV7Ks61xAeHPGeKF3-Re9HKFNPhkGCF4YZRUIs-c0TPVSUApEzLCCvp1a7a6B6e7QiUVbGiQC78xl0qvSN4zCKaR73K8oOMezmxExCrjRjzovyVw1c1m1S55QIKSaEXkg_gEZSmIvL_Qn1FW8u56AqKcCNU9j_KAhN8YnCQR9-vlwsZhoyO9yIkS5GLm1FEOdApo8pEM8cm6vQ9oF9CSQEm_gq6mW6OBPe_lzAYUHxRugvFImu4t7rewwAO2iRmTD1zUpTJ3USZb_flskiGm0RnmtmuUBUilOvYvzgnILa9LgNYxJOXksldJ-R-aJWan3U1rF-oY6uC0AzDB6hSXdYEC31sJjz2n_coR43xss5UKpWsFk5CmRBvsBE4JZfrPfCO2S3XU1xeusGrH8dzPCdLIMmowo627B2YLthV5yoppXR-b6P3jindO9XXHkrM-NGyz4TJzrO1-6PmJP4GZrig1E-GjFZ3ue4OJOqUZXMLTw8J2MFqKh1Jj2Fp9cCZFd4YMJenptGlyCy6SbGxGgEkrHm5w07k0G381FM1rtvhJq49uILCKchOfMFTk7pCm2WAv-A-OuFnqm0rDBG5PUEypUn0Nt4hskiuqIj2SvnawDsN9bwgBHFGp_t3MuAQ3BixfhI1ZRnYIFhXAQ2JIXXN_8QIHd7bIzxzq_ym5lzy--0tL-ibZMZk2Am5q5V0Kog8KQC5791FyybwGOXMPUW_62SqZwF2Twl0NTAezhd4guKPe2ztsrrCMfQ4wrBGxy-Ywu2nLlgwHCTvSTNLFv4qATGEI_EKdCsNCejgr9WNSMX2RU8FLPigbqAFk2VvIDwQXNmDJINPEj_k6fvhP7rvP2Gl72rtgBKOBPIHyRbNS6u0X9wDr1u3xux0FtyvB3t9elxAMK_-o4jewCEgwq1-88YiewKDlvTMmselN49Jg_mVksdRoIbvahgnLGwQdedxDLnxykR4SW7Qw4K_Kxf9Fla0VL_yI-3DoxlMMc3j56mYuo08UKnPwG8bsd3JP-OHEi45h2nh14aWBEqjejcl7LLUWB0aXanu-5kGvPTUj3N9LNGw4h_voCa_F-4IUk2cj8NXvcqO=w1920-h929)
- **Compass calibration**
Calibrate the compass  
![](https://lh3.googleusercontent.com/fife/AAbDypBfSTRP_zLe6ElJU3DmDhECoI8SUKoXrNoVhygPmR-7G5bZrRr5LaoHGOdHfR2g08ff1kFfpsh0VxV0GMlQW-b5_oHd6iEwsv-ilc_BkdtpIgDJ6gRUlRCHMPOFsxwj4-MTSyQ33xugjRUHky0L0LUt1vPt3GPlJJPpmSO46ZPUktFme0zinl3SKqqbtQoEwHAEzXJHbdanGHIMxBWb1mR2SaaXlLRljl7xJZG2YpPcL_b3JpLgJJtiPDHfB9wKY_hZ9XGbvVu8x1bJBqPkCRlzzI_-9WQZgqme5qj21yRpYwqkgdxAELwuL6AK5niekou3bOk79szrDizoEmnmIfCqtdzAIWaCZ7kjDg5-Axi25C0Bos9DraMAPUqV7dsCNZSbsEHqzVPEnj0kyLAJLAckNStR1sP-ZO3oRdtCUUwt3shhsnHdLeNgR3QU_N-DHA6adR86Lpr8i4bclSdpcpJdxFjecsENJZVQyJYzi1qxzDMnu7U84Su9ldeARwua56qDa1-ibCls9VVmNQO2RrWGrmO-I_HMG1JmGptUEiQCetDFI5-NUFss_tFOSbmCRsN-lOrtfyY3BP9mMe7yM5kp-49VJ2chdkMrT-J_1GkDQ_wDECcV7VP_WERTMnGn7wbJxQ9uC0Z1rE-GIzn_7vMJMU1Sce8SCOZUwCgRlBZEwBr5tYCXGvFtn4vzhlgsUM8jq-tWkp7z-QFJuIh4r3YmgPyCz9qftTtuz_qNjT405sOsUQBxWgAnwFdPXEw7hvIDx-eitMYwgKtj-F3tLjxV0tQvqtkDPJ3_0BtzJHE7v8xtOK232v3CkNpSmsK-CMMZ2h4PXOX2dLCBcmodNjrPUtGhrAkICBJ4rOUAfi6uPTcgiO2-Y79zZ_eVuiI2ESb-uq56YFNIAlMvBXCbWY1-EEbRaDfEDdpKZ8a1dK7Ud64m0r3YRluUF2B_IF33-Mo3B5kIRAQvVg6qUQBn_ZY4W9L4Ch5bjxiGghGI6Aq-jINr_cL6PkTfVwRz75WFROELW3T9yYbsdls3hbA8HGhjBv3CyxzkDBwFU6LldTh7wUXlltZTs7N48doZENRYYPPgSagHzXqF-_LVTkukU49kjVohoDi1MwL7EXLpiBpIRFDIfPUfvHeYltd9gJW5hJ_VNnuIxWZddJBTNg-JvGNN-pbZBo8YdB4qoYRsVAnGOviTcHQmkmeL1BFBZ2Sh_AvXa-0LU_0HOr1I4mnPaO98x3DfEgvF09nHbrI_ni-P-_3MbpgxpQ2-LVP2VuNnWC7bHtkBHcglTIRpp0LLy9JguoZRAOxnH4jslCUNjSAy37VAmGpl-QtzybrppwDodHXSJpNU-8tlbhSPWSArprRESf4Y3MGD-FPIOuvxcisMphyGqFcN_La9kvaDfDNNVGhPq2JILp7a88Vb0CusF-ZH36tufmF7h87LyiZTCdHlTlrVcOQAZJ3r=w1920-h929)

### **Part Five:** Stopping the robot
This part of the robot ensures that the robot **stops in the correct position on the field.**
Basically, the program counts how many time the robot took a 90 degree turn
If it turns more than 4 times the program will run for 1.5 second and the program ends.

# **THE END**
For further questions please email robloxplay41@gmail.com

   [Yothinburana School Robot Club]: <https://ybrobot.club/>
   [Original Flipped Digital Lab]: <https://ofdl.tw/en/>
   [EV3FW-V1.21C-OFDL.bin]: <https://github.com/a10036gt/EV3-BatteryInfo-Block/releases/download/v1.2/EV3FW-V1.21C-OFDL.bin>
   [OFDL-EV3_Blocks-Collections]: <https://github.com/a10036gt/OFDL-EV3_Blocks-Collections/releases/tag/2020.09.12>
   [Pixy Blocks and Examples]: <https://github.com/charmedlabs/pixy/raw/master/releases/lego/lego_pixy-1.1.4.zip>
   [EV3 Education Lab]: <https://e498eb58-16e9-491c-8ce4-828510ab7c41.filesusr.com/archives/1f66bb_4708cf7510f64585bd447c26a4110fc5.zip?dn=LME-EV3_Full-setup_1.4.5_en-US_WIN32.zip>
   [Pixymon V2]: <https://github.com/charmedlabs/pixy/raw/master/releases/pixymon_windows/pixymon_windows-2.0.9.exe>
   [Wikipedia - Bezier Curve]: <https://en.wikipedia.org/wiki/B%C3%A9zier_curve>
   [Arduino-pico Github]: <https://github.com/earlephilhower/arduino-pico>
   [Arduino IDE 2.0.1]: <https://www.arduino.cc/en/software>


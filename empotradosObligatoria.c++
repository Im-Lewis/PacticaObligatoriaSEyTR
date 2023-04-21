//----------------------------------------------------------------------------------
// VARIABLES //

int umbral; // Valor del umbral
int LDR = 0; // LDR está en el pin analógico 0
int boton = 2; // Pin del botón
int zumbador = 8; // Pin del zumbador
int valLDR = 0; //Valor del LDR
int buttonState = 0; //Estado del boton

int m1_reproducida = 0; //0=melodia 1 - 1=melodia2
int m2_reproducida = 0;

//----------------------------------------------------------------------------------
//CÓDIGO //

void setup(){
  pinMode(boton, INPUT);
  pinMode(LDR, INPUT);

  randomSeed(analogRead(0)); // Se inicializa la semilla (comprobar que sea aleatoria)
  Serial.begin(9600); //Iniciamos el monitor serie
  umbral = random(300, 800); //poner random
  Serial.print("El valor del umbral: "); 
  Serial.println(umbral);

  //melodia inicial 
  valLDR = analogRead(LDR); //Comprobar valor de luminodidad 
  if(valLDR >= umbral){
    Serial.print("Botón no pulsado, superado el umbral "); 
    Serial.print(valLDR);
    Serial.println(" melodía 1.");

    melodias(1);
    m1_reproducida = 1; 
  }
  else{
    Serial.print("Botón no pulsado, no superado el umbral "); 
    Serial.print(valLDR);
    Serial.println(" melodía 2.");

    melodias(2); 
    m2_reproducida = 1;
  }
}

void loop(){
  buttonState = digitalRead(boton); 
  //Mientras el boton este pulsado 
  while(buttonState == HIGH){
    valLDR = analogRead(LDR); //Comprobar valor de luminosidad
    if(valLDR >= umbral){
      Serial.print("Botón pulsado, superado el umbral "); 
      Serial.print(valLDR);
      Serial.println(" melodía 1.");

      //Comprobamos que melodia era la anterior (anterior == 1)
      if(m1_reproducida == 1){
        m1_reproducida = 0; 
      }
      else if(m2_reproducida == 1){
        //triple pitido al cambiar de melodia
        for (int i = 0; i < 3; i++){
          tone(zumbador, 900);
          delay(500);
          noTone(zumbador);
          delay(100); 
        }
        m2_reproducida = 0; 
      }

      melodias(1); //Reproduce melodia 1
      m1_reproducida = 1; //anterior la ponemos a uno 
    }

    else {
      Serial.print("Botón pulsado, no superado el umbral "); 
      Serial.print(valLDR);
      Serial.println(" melodía 2.");
      if(m1_reproducida == 1){
        //triple pitido al cambiar de melodia
        for (int i = 0; i < 3; i++){
          tone(zumbador, 900);
          delay(500);
          noTone(zumbador);
          delay(100);
        }
        m1_reproducida = 0; 
      }
      else if(m2_reproducida == 1){
        m2_reproducida = 0; 
      }
      melodias(2); //Reproduce melodia 2
      m2_reproducida = 1;  //anterior la ponemos a uno 
    }
    buttonState = digitalRead(boton); 
  }

  //Mientras el boton no este pulsado 
  while(buttonState == LOW){
    //Reproducimos la anterior tres veces con silencios 
    if(m1_reproducida == 1){
      Serial.print("Botón no pulsado, superado el umbral "); 
      Serial.print(valLDR);
      Serial.println(" melodía 1.");
      botonNoPulsado(1); //reproducir melodia 1 
    }
    else if(m2_reproducida == 1){
      Serial.print("Botón no pulsado, no superado el umbral "); 
      Serial.print(valLDR);
      Serial.println(" melodía 2.");
      botonNoPulsado(2); //reproducir melodia 2 
    }
    buttonState = digitalRead(boton); 
  }
  buttonState = digitalRead(boton);

}//Fin de programa


//------------------------------------------------------------------------------------------------
//FUNCIONES AUXILIARES

void melodias(int melodia){
  //Melodia de 15 segundos (Piratas del caribe)
  if(melodia == 1){
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100); //1500
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100); //3000
    tone(zumbador,293.66,200);
    delay(200);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,293.66,100);
    delay(100);
    tone(zumbador,440,100);
    delay(100);
    tone(zumbador,523.25,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(200); //4000
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,659.25,100);
    delay(100);
    tone(zumbador,698.45,100);
    delay(200);
    tone(zumbador,698.45,100);
    delay(200);
    tone(zumbador,698.45,100);
    delay(100);
    tone(zumbador,783.99,100);
    delay(100);
    tone(zumbador,659.25,100);
    delay(200); //5k
    tone(zumbador,659.25,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,523.25,100);
    delay(100);
    tone(zumbador,523.25,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(300);
    tone(zumbador,440,100);
    delay(100);
    tone(zumbador,523.25,100);
    delay(100); //6k
    tone(zumbador,587.33,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,659.25,100);
    delay(100);
    tone(zumbador,698.45,100);
    delay(200);
    tone(zumbador,698.45,100);
    delay(200); //7k
    tone(zumbador,698.45,100);
    delay(100);
    tone(zumbador,783.99,100);
    delay(100);
    tone(zumbador,659.25,100);
    delay(200);
    tone(zumbador,659.25,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,523.25,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(400);
    tone(zumbador,440,100);
    delay(100);
    tone(zumbador,523.25,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(200);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,698.45,100);
    delay(100); //9k
    tone(zumbador,783.99,100);
    delay(200);
    tone(zumbador,783.99,100);
    delay(200);
    tone(zumbador,783.99,100);
    delay(100);
    tone(zumbador,880,100);
    delay(100);
    tone(zumbador,932.33,100);
    delay(200);
    tone(zumbador,932.33,100);
    delay(200); //10k
    tone(zumbador,880,100);
    delay(100);
    tone(zumbador,783.99,100);
    delay(100);
    tone(zumbador,880,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(300);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,659.25,100);
    delay(100);
    tone(zumbador,698.45,100);
    delay(200); //11k
    tone(zumbador,698.45,100);
    delay(200);
    tone(zumbador,783.99,100);
    delay(200);
    tone(zumbador,880,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(300);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,698.45,100);
    delay(100); //12k
    tone(zumbador,659.25,100);
    delay(200);
    tone(zumbador,659.25,100);
    delay(200);
    tone(zumbador,698.45,100);
    delay(100);
    tone(zumbador,587.33,100);
    delay(100);
    tone(zumbador,659.25,100);
    delay(400); //13k
    tone(zumbador,880,100);
    delay(100);
    tone(zumbador,1046.50,100);
    delay(100);
    tone(zumbador,1174.66,100);
    delay(200);
    tone(zumbador,1174.66,100);
    delay(200);
    tone(zumbador,1174.66,100);
    delay(100);
    tone(zumbador,1318.51,100);
    delay(100);
    tone(zumbador,1396.91,100);
    delay(200); //14k
    tone(zumbador,1396.91,100);
    delay(200);
    tone(zumbador,1396.91,100);
    delay(100);
    tone(zumbador,1567.98,100);
    delay(100);
    tone(zumbador,1318.51,100);
    delay(200);
    tone(zumbador,1318.51,100);
    delay(200);
    tone(zumbador,1174.66,100);
    delay(100);
    tone(zumbador,1046.50,100);
    delay(100); //15k
  }
  else if(melodia == 2){
    //Melodia de 10 segundos 
    tone(zumbador, 440, 500);
    delay(500+50);
    tone(zumbador, 440, 500);
    delay(500+50);     
    tone(zumbador, 440, 500); 
    delay(500+50);
    tone(zumbador, 349, 350);  
    delay(350+50);
    tone(zumbador, 523, 150);
    delay(150+50); //2250
    
    tone(zumbador, 440, 500);
    delay(500+50);
    tone(zumbador, 349, 350);
    delay(350+50); //3200
    tone(zumbador, 523, 150);
    delay(150+50);
    tone(zumbador, 440, 1000);   
    delay(1000+50); //4450
   
    tone(zumbador, 659, 500);
    delay(500+50); //5k
    tone(zumbador, 659, 500);
    delay(500+50);
    tone(zumbador, 659, 500); 
    delay(500+50);   
    tone(zumbador, 349, 350);
    delay(350+50); 
    tone(zumbador, 523, 150);
    delay(150+50); //6700
    
    tone(zumbador, 415, 500);
    delay(500+50);
    tone(zumbador, 349, 350);
    delay(350+50); //7650
    tone(zumbador, 523, 150);
    delay(150+50);
    tone(zumbador, 440, 1000);
    delay(1000+50); //7900
    
    tone(zumbador, 440, 500);
    delay(500+50); //8450
    tone(zumbador, 440, 350);
    delay(350+50); //8850
    tone(zumbador, 440, 150);
    delay(150+50); //9050
    tone(zumbador, 440, 500);
    delay(500+50); //9600
    tone(zumbador, 415, 250); 
    delay(250+50); //9900
    tone(zumbador, 783, 250);
    delay(100);
  }
  noTone(zumbador); 
}

void botonNoPulsado(int melodia){
  //Reproduce la melodia correspondiente tres veces 
  for (int i = 0; i < 3; i++){
    melodias(melodia); 
    noTone(zumbador); 
    delay(5000); 
  }
}

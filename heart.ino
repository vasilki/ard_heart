void setup()
{ 
  DDRB = 0xFF;
  PORTB = 0xFF;

  DDRC = 0x3F;
  PORTC = 0x3F;

  DDRD = 0xFF;
  PORTD = 0x7F;
}
//------------------------------------------------------
void loop()
{ 
  for (byte j = 0; j < 3; j++)
    Effect_1();
  for (byte j = 0; j < 3; j++)
    Effect_2();
  for (byte j = 0; j < 3; j++)
    Effect_3();
  for (byte j = 0; j < 3; j++)
    Effect_4();
  for (byte j = 0; j < 3; j++)
    Effect_5();
    
  Effect_6();
  
  for (byte j = 0; j < 3; j++)
  {
    for (unsigned int i = 0; i < 30000; i++)
    Effect_7();
  }
  
  for (byte j = 0; j < 3; j++)
    Effect_8();
  for (byte j = 0; j < 3; j++)
    Effect_9();
  for (byte j = 0; j < 3; j++)
    Effect_10();
  for (byte j = 0; j < 3; j++)
    Effect_11();
}
//------------------------------------------------------------
//Р­С„С„РµРєС‚ 1
void Effect_1()
{
  for (byte j = 0; j <= 7; j++)
  {
    PORTB &= ~(1 << j);
    delay(75);
  }

  for (byte j = 0; j <= 5; j++)
  {
    PORTC &= ~(1 << j);
    delay(75);
  }

  for (byte j = 0; j < 7; j++)
  {
    PORTD &= ~(1 << j);
    delay(75);
  }

  for (byte j = 0; j < 2; j++)
  {
    All_OFF();
    delay(150);
    All_ON();
    delay(150);
  }

  All_OFF();
}
//---------------------------------------------------------
//Р­С„С„РµРєС‚ 2
void Effect_2()
{
  for (byte j = 0; j <= 7; j++)
  {
    PORTB &= ~(1 << j);
    delay(75);
    PORTB |= (1 << j);
  }

  for (byte j = 0; j <= 5; j++)
  {
    PORTC &= ~(1 << j);
    delay(75);
    PORTC |= (1 << j);
  }

  for (byte j = 0; j < 7; j++)
  {
    PORTD &= ~(1 << j);
    delay(75);
    PORTD |= (1 << j);
  }
}
//---------------------------------------------------------
//Р­С„С„РµРєС‚ 3
void Effect_3()
{
  byte Value;
  boolean ClearFlag;
    
  //РІРєР»СЋС‡РµРЅРёРµ
  while ((PORTB != 0) || ((PORTC & 0x3F) != 0) || ((PORTD & 0x7F) != 0))
  {
    //PORTB
    if (PORTB != 0)
    {
      Value = random(0, 8);
      ClearFlag = false;
      if ((PORTB & (1 << Value)) != (1 << Value))
      {
        for (byte j = Value; j <= 7; j++)
        {
          if ((PORTB & (1 << j)) == (1 << j))
          {
            PORTB &= ~(1 << j);
            ClearFlag = true;
            break;
          }
        }

        if (!ClearFlag)
        {
          for (byte j = 0; j < Value; j++)
          {
            if ((PORTB & (1 << j)) == (1 << j))
            {
              PORTB &= ~(1 << j);
              ClearFlag = true;
              break;
            }
          }
        }
      }

      else
      {
        PORTB &= ~(1 << Value);
      }
    }
    //PORTC
    if ((PORTC & 0x3F) != 0)
    {
      Value = random(0, 6);
      ClearFlag = false;
      if ((PORTC & (1 << Value)) != (1 << Value))
      {
        for (byte j = Value; j <= 7; j++)
        {
          if ((PORTC & (1 << j)) == (1 << j))
          {
            PORTC &= ~(1 << j);
            ClearFlag = true;
            break;
          }
        }

        if (!ClearFlag)
        {
          for (byte j = 0; j < Value; j++)
          {
            if ((PORTC & (1 << j)) == (1 << j))
            {
              PORTC &= ~(1 << j);
              ClearFlag = true;
              break;
            }
          }
        }
      }

      else
      {
        PORTC &= ~(1 << Value);
      }
    }
    //PORTD
    if ((PORTD & 0x7F) != 0)
    {
      Value = random(0, 7);
      ClearFlag = false;
      if ((PORTD & (1 << Value)) != (1 << Value))
      {
        for (byte j = Value; j <= 7; j++)
        {
          if ((PORTD & (1 << j)) == (1 << j))
          {
            PORTD &= ~(1 << j);
            ClearFlag = true;
            break;
          }
        }

        if (!ClearFlag)
        {
          for (byte j = 0; j < Value; j++)
          {
            if ((PORTD & (1 << j)) == (1 << j))
            {
              PORTD &= ~(1 << j);
              ClearFlag = true;
              break;
            }
          }
        }
      }

      else
      {
        PORTD &= ~(1 << Value);
      }
    }

      delay(150);
  }
    
  delay(1000);

  //РІС‹РєР»СЋС‡РµРЅРёРµ
  while ((PORTB != 0xFF) || ((PORTC & 0x3F) != 0x3F) || ((PORTD & 0x7F) != 0x7F))
  {
    //PORTB
    if (PORTB != 0xFF)
    {      
      Value = random(0, 8);
      ClearFlag = false;
      if ((PORTB & (1 << Value)) == (1 << Value))
      {
        for (byte j = Value; j <= 7; j++)
        {
          if ((PORTB & (1 << j)) != (1 << j))
          {
            PORTB |= (1 << j);
            ClearFlag = true;
            break;
          }
        }

        if (!ClearFlag)
        {
          for (byte j = 0; j < Value; j++)
          {
            if ((PORTB & (1 << j)) != (1 << j))
            {
              PORTB |= (1 << j);
              ClearFlag = true;
              break;
            }
          }
        }
      }

      else
      {
        PORTB |= (1 << Value);
      }
    }
    //PORTC
    if ((PORTC & 0x3F) != 0x3F)
    {
      Value = random(0, 6);
      ClearFlag = false;
      if ((PORTC & (1 << Value)) == (1 << Value))
      {
        for (byte j = Value; j <= 7; j++)
        {
          if ((PORTC & (1 << j)) != (1 << j))
          {
            PORTC |= (1 << j);
            ClearFlag = true;
            break;
          }
        }

        if (!ClearFlag)
        {
          for (byte j = 0; j < Value; j++)
          {
            if ((PORTC & (1 << j)) != (1 << j))
            {
              PORTC |= (1 << j);
              ClearFlag = true;
              break;
            }
          }
        }
      }

      else
      {
        PORTC |= (1 << Value);
      }
    }
    //PORTD
    if ((PORTD & 0x7F) != 0x7F)
    {
      Value = random(0, 7);
      ClearFlag = false;
      if ((PORTD & (1 << Value)) == (1 << Value))
      {
        for (byte j = Value; j < 7; j++)
        {
          if ((PORTD & (1 << j)) != (1 << j))
          {
            PORTD |= (1 << j);
            ClearFlag = true;
            break;
          }
        }

        if (!ClearFlag)
        {
          for (byte j = 0; j < Value; j++)
          {
            if ((PORTD & (1 << j)) != (1 << j))
            {
              PORTD |= (1 << j);
              ClearFlag = true;
              break;
            }
          }
        }
      }

      else
      {
        PORTD |= (1 << Value);
      }
    }

    delay(150);
  }
    
  delay(1000);
}
//------------------------------------------------------------
//Р­С„С„РµРєС‚ 4
void Effect_4()
{ 
  All_ON();
  delay(750);
  All_OFF();
  delay(750); 
}
//---------------------------------------------------------
//Р­С„С„РµРєС‚ 5
void Effect_5()
{
  PORTB &= ~(1 << 0);
  delay(75);
  
  for (byte i = 1; i <= 7; i++)
  {
    PORTB &= ~(1 << i);
    PORTD &= ~(1 << (7 - i));
    delay(75);
  }

  for (byte i = 0; i <= 2; i++)
  {
    PORTC &= ~((1 << i) | (1 << (5 - i)));
    delay(75);
  }
  
  delay(750);

  for (byte i = 3; i <= 5; i++)
  {
    PORTC |= ((1 << (5 - i)) | (1 << i));
    delay(75);
  }

  for (byte i = 7; i >= 1; i--)
  {
    PORTB |= (1 << i);
    PORTD |= (1 << (7 - i));
    delay(75);
  }

  PORTB |= (1 << 0);
  delay(75);

  delay(750);
}
//---------------------------------------------------------
//Р­С„С„РµРєС‚ 6
void Effect_6()
{
  const unsigned int DotUnit = 100;
  const unsigned int DashUnit = 3 * DotUnit;
  const unsigned int WordSpace = 7 * DotUnit;

  //РЇ
  for (byte i = 0; i < 2; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
    //-
    All_ON();
    delay(DashUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ СЃР»РѕРІР°РјРё
  delay(WordSpace - DotUnit);

  //С‚РµР±СЏ
  //С‚
  // -
  All_ON();
  delay(DashUnit);
  All_OFF();
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit);
  //Рµ
  //.
  All_ON();
  delay(DotUnit);
  All_OFF();
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit);
  //Р±
  //-
  All_ON();
  delay(DashUnit);
  All_OFF();
  delay(DotUnit);
  for (byte i = 0; i < 3; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit - DotUnit);

  //СЏ
  for (byte i = 0; i < 2; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
    //-
    All_ON();
    delay(DashUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ СЃР»РѕРІР°РјРё
  delay(WordSpace - DotUnit);

  //Р»СЋР±Р»СЋ
  //Р»
  //.
  All_ON();
  delay(DotUnit);
  All_OFF();
  delay(DotUnit);
  //-
  All_ON();
  delay(DashUnit);
  All_OFF();
  delay(DotUnit);
  for (byte i = 0; i < 2; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit - DotUnit);
  //СЋ
  for (byte i = 0; i < 2; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
  }
  for (byte i = 0; i < 2; i++)
  {
    //-
    All_ON();
    delay(DashUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit - DotUnit);
  //Р±
  //-
  All_ON();
  delay(DashUnit);
  All_OFF();
  delay(DotUnit);
  for (byte i = 0; i < 3; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit - DotUnit);
  //Р»
  //.
  All_ON();
  delay(DotUnit);
  All_OFF();
  delay(DotUnit);
  //-
  All_ON();
  delay(DashUnit);
  All_OFF();
  delay(DotUnit);
  for (byte i = 0; i < 2; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ Р±СѓРєРІР°РјРё
  delay(DashUnit - DotUnit);
  //СЋ
  for (byte i = 0; i < 2; i++)
  {
    //.
    All_ON();
    delay(DotUnit);
    All_OFF();
    delay(DotUnit);
  }
  for (byte i = 0; i < 2; i++)
  {
    //-
    All_ON();
    delay(DashUnit);
    All_OFF();
    delay(DotUnit);
  }
  //РїР°СѓР•Р° РјРµР¶РґСѓ СЃР»РѕРІР°РјРё
  delay(WordSpace - DotUnit);
}
//---------------------------------------------------------
//Р­С„С„РµРєС‚ 7
void Effect_7()
{
  const byte BrightnessRate = 100;
  const byte Period = 100;
  static byte PeriodCounter = 0;
  static boolean State = false;
  static byte DutyCycle = 0;
  static byte DutyCycleCounter = 0;
  
  delayMicroseconds(200);

  DutyCycleCounter++;
  
  if (DutyCycleCounter == BrightnessRate)
  {
    if (!State)
    {
      DutyCycle++;
      if (DutyCycle == PeriodCounter)
      {
        State = true;
      }
    }
  
    else
    {
      DutyCycle--;
      if (DutyCycle == 0)
      {
        State = false;
      }
    }

    DutyCycleCounter = 0;
  }

  if (PeriodCounter < DutyCycle)
    All_ON();
  else
    All_OFF();
  
  PeriodCounter++;

  if (PeriodCounter == Period)
    PeriodCounter = 0;
}
//----------------------------------------------
//Р­С„С„РµРєС‚ 8
void Effect_8() 
{
  All_OFF();
  PORTB &= ~((1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7));
  PORTC &= ~((1 << 1) | (1 << 4));
  PORTD &= ~((1 << 0) | (1 << 2) | (1 << 4) | (1 << 6));
  delay(300);
  All_OFF();
  PORTB &= ~((1 << 0) | (1 << 2) | (1 << 4) | (1 << 6));
  PORTC &= ~((1 << 0) | (1 << 2) | (1 << 3) | (1 << 5));
  PORTD &= ~((1 << 1) | (1 << 3) | (1 << 5));
  delay(300);
}
//----------------------------------------------
//Р­С„С„РµРєС‚ 9
void Effect_9() 
{
  All_OFF();
  PORTB = 0;
  PORTC &= ~((1 << 0) | (1 << 1) | (1 << 2));
  delay(300);
  All_OFF();
  PORTB &= ~(1 << 0);
  PORTC &= ~((1 << 3) | (1 << 4) | (1 << 5));
  PORTD = 0;
  delay(300);
}
//----------------------------------------------
//Р­С„С„РµРєС‚ 10
void Effect_10()
{  
  PORTB &= ~(1 << 0);

  for (byte i = 1; i <= 7; i++)
  {
    PORTB &= ~(1 << i);
    if (i < 4)
      PORTC |= (1 << (i + 2));
    else
      PORTD |= (1 << (i - 4));
    delay(150);    
  }

  for (byte i = 0; i <= 2; i++)
  {
    PORTC &= ~(1 << i);
    PORTD |= (1 << (i + 4));
    delay(150);    
  }

  for (byte i = 7; i >= 1; i--)
  {
    PORTD &= ~(1 << (i - 1));
    if (i > 4)
      PORTC |= (1 << (i - 5));
    else
      PORTB |= (1 << (i + 3));
    delay(150);
  }

  for (byte i = 5; i >= 3; i--)
  {
    PORTC &= ~(1 << i);
    PORTB |= (1 << (i - 2));
    delay(150);    
  }
}
//----------------------------------------------
//Р­С„С„РµРєС‚ 11
void Effect_11()
{
  PORTB &= ~(1 << 0);
  
  for (byte i = 7; i >= 1; i--)
  {
    PORTD &= ~(1 << (i - 1));
    if (i > 4)
      PORTC &= ~(1 << (i - 5));
    else
      PORTB &= ~(1 << (i + 3));
    delay(150);
  }

  for (byte i = 5; i >= 3; i--)
  {
    PORTC &= ~(1 << i);
    PORTB &= ~(1 << (i - 2));
    delay(150);    
  }

  for (byte i = 1; i <= 7; i++)
  {
    PORTB |= (1 << i);
    if (i < 4)
      PORTC |= (1 << (i + 2));
    else
      PORTD |= (1 << (i - 4));
    delay(150);    
  }

  for (byte i = 0; i <= 2; i++)
  {
    PORTC |= (1 << i);
    PORTD |= (1 << (i + 4));
    delay(150);    
  }

  PORTB |= (1 << 0);
  delay(150);
}
//----------------------------------------------
void All_ON()
{
  PORTB = 0;
  PORTC = 0;
  PORTD = 0x80;
}
//----------------------------------------------
void All_OFF()
{
  PORTB = 0xFF;
  PORTC = 0x3F;
  PORTD = 0x7F;
}

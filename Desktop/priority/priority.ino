int app1 = 20;
int app2 = 80;
int pInit = 2000;
int pReq = app1 + app2;
int pMin = 0.1 * pInit;
int pInst = pInit;
int t1;
int t2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  t1 = millis();
  Serial.println("Initial: " + (String)pInit);
  Serial.println("Minimum: " + (String)pMin);
  Serial.println("Required: " + (String)pReq);
  Serial.println("Inst: " + (String)pInst);
}

void loop() {
  // put your main code here, to run repeatedly:
  t2 = millis();
  
  if((t2 - t1) == 2000) {
    t1 = millis();
    pInst = pInst - pReq ;
    
    if(pInst <= 3*(pMin + pReq)) {
      pReq = pReq - app2;
      app2 = 0; 
    }

    if(pInst < pMin){
      Serial.println("Dead");
    } else {
      Serial.println("Inst: " + (String) pInst);
    }
  }
}

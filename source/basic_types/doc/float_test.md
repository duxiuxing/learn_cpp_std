(7)double/float->CString
   double data;
   CString.Format("%.2f",data); //保留2位小数

(8)CString->double
   CString s="123.12";
   double   d=atof(s);   
 
(9)string->double
  double d=atof(s.c_str());


char str[10];
double a=123.321;
sprintf(str,"%.3lf",a);

char str[]="123.321";
double a;
sscanf(str,"%lf",&a);
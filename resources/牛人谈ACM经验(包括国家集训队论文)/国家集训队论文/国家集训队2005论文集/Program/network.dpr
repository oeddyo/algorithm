Program Network;

Const
  inputfile='input.txt';
  outputfile='output.txt';
  maxn=500;
  maxnum=1e+20;

Type
  ptype=Record
    x,y:longint;
  End;
  rtype=Record
    point:longint;
    cost:real;
  End;

Var
  a:Array [1..maxn,1..maxn] of real;
  p:Array [1..maxn] of ptype;
  f:Array [1..maxn] of longint;
  b:Array [1..maxn] of rtype;
  e:Array [1..maxn] of real;
  n,k:longint;

  Function Dis(x1,y1,x2,y2:longint):real;
  Begin
    Dis:=Sqrt(Sqr(x1-x2)+Sqr(y1-y2));
  End;

  Procedure Init;
  Var
    i,j:longint;
  Begin
    Assign(input,inputfile);
    Reset(input);
    Read(n,k); If k<1 Then k:=1; If k>n Then k:=n;
    For i:=1 to n Do Read(p[i].x,p[i].y);
    Close(input);
    For i:=1 to n Do
      For j:=1 to n Do
        a[i,j]:=Dis(p[i].x,p[i].y,p[j].x,p[j].y);
  End;

  Procedure MST;
  Var
    i,j:longint;
    temp:real;
    tb:rtype;
  Begin
    Fillchar(f,Sizeof(f),0);
    For i:=1 to n Do
    Begin
      b[i].point:=i;
      If i=1 Then b[i].cost:=0 Else b[i].cost:=maxnum;
    End;
    For i:=1 to n-1 Do
    Begin
      For j:=i+1 to n Do
        If b[j].cost<b[i].cost Then
        Begin
          tb:=b[i]; b[i]:=b[j]; b[j]:=tb;
        End;
      For j:=i+1 to n Do
      Begin
        temp:=a[b[i].point,b[j].point];
        If temp<b[j].cost Then
        Begin
          b[j].cost:=temp;
          f[b[j].point]:=b[i].point;
        End;
      End;
    End;
  End;

  Function Find(p,q,pos:longint):real;
  Var
    r,i,j:longint;
    k:real;
  Begin
    r:=Random(q-p+1)+p;
    k:=e[r];
    e[r]:=e[p];
    i:=p; j:=q;
    While i<j Do
    Begin
      While (i<j) and (k>=e[j]) Do Dec(j);
      e[i]:=e[j];
      While (i<j) and (e[i]>=k) Do Inc(i);
      e[j]:=e[i];
    End;
    e[i]:=k;
    If i=pos
      Then Find:=k
      Else If i<pos
             Then Find:=Find(i+1,q,pos)
             Else Find:=Find(p,i-1,pos);
  End;           

  Procedure Answer;
  Var
    i:longint;
  Begin
    For i:=1 to n Do
      If i=1 Then e[i]:=0 Else e[i]:=a[i,f[i]];
    Assign(output,outputfile);
    Rewrite(output);
    Writeln(Find(1,n,k):0:2);
    Close(output);
  End;

Begin
  Init;
  MST;
  Answer;
End.


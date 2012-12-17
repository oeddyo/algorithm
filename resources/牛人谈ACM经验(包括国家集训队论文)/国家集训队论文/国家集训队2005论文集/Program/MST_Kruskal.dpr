Program MST_Kruskal;

Const
  inputfile='mst.in';
  outputfile='mst.out';
  maxn=200;
  maxe=maxn*maxn;

Type
  edgetype=Record
    x,y,c:longint;
  End;

Var
  e:Array [1..maxe] of edgetype;
  f:Array [1..maxn] of longint;
  n,m,ans:longint;

  Procedure Init;
  Var
    i:longint;
  Begin
    Assign(input,inputfile);
    Reset(input);
    Read(n,m);
    For i:=1 to m Do Read(e[i].x,e[i].y,e[i].c);
    Close(input);
  End;

  Procedure Qksort(p,q:longint);
  Var
    r,i,j:longint;
    k:edgetype;
  Begin
    r:=Random(q-p+1)+p;
    k:=e[r];
    e[r]:=e[p];
    i:=p; j:=q;
    While i<j Do
    Begin
      While (i<j) and (k.c<=e[j].c) Do Dec(j);
      e[i]:=e[j];
      While (i<j) and (e[i].c<=k.c) Do Inc(i);
      e[j]:=e[i];
    End;
    e[i]:=k;
    If p<i-1 Then Qksort(p,i-1);
    If i+1<q Then Qksort(i+1,q);
  End;

  Function top(i:longint):longint;
  Begin
    If i<>f[i] Then f[i]:=top(f[i]);
    top:=f[i];
  End;

  Procedure Union(i,j,c:longint);
  Var
    x,y:longint;
  Begin
    x:=top(i); y:=top(j);
    If x<>y Then
    Begin
      Inc(ans,c);
      f[y]:=x;
    End;
  End;

  Procedure Main;
  Var
    i:longint;
  Begin
    Qksort(1,m);
    For i:=1 to n Do f[i]:=i;
    ans:=0;
    For i:=1 to m Do Union(e[i].x,e[i].y,e[i].c);
  End;

  Procedure Answer;
  Begin
    Assign(output,outputfile);
    Rewrite(output);
    Writeln(ans);
    Close(output);
  End;

Begin
  Init;
  Main;
  Answer;
End.


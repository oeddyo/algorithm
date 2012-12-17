Program MST_Prim;

Const
  inputfile='mst.in';
  outputfile='mst.out';
  maxn=200;

Type
  link=^node;
  node=Record
    data,cost:longint;
    next:link;
  End;
  rtype=Record
    point,cost:longint;
  End;

Var
  a:Array [1..maxn] of link;
  h:Array [1..maxn] of rtype;
  pos:Array [1..maxn] of longint;
  n,m,htail,ans:longint;

  Procedure Insert(x,y,c:longint);
  Var
    d:link;
  Begin
    New(d); d^.data:=y; d^.cost:=c;
    d^.next:=a[x]; a[x]:=d;
  End;

  Procedure Init;
  Var
    i,x,y,c:longint;
  Begin
    Assign(input,inputfile);
    Reset(input);
    Read(n,m);
    For i:=1 to m Do
    Begin
      Read(x,y,c);
      Insert(x,y,c); Insert(y,x,c);
    End;
    Close(input);
  End;

  Procedure Go_Up(j:longint);
  Var
    x:rtype;
    i:longint;
  Begin
    x:=h[j];
    While j>1 Do
    Begin
      i:=j div 2;
      If h[i].cost<=x.cost Then Break;
      h[j]:=h[i]; pos[h[j].point]:=j;
      j:=i;
    End;
    h[j]:=x; pos[x.point]:=j;
  End;

  Procedure Go_Down(i:longint);
  Var
    x:rtype;
    j:longint;
  Begin
    x:=h[i];
    While i+i<=htail Do
    Begin
      j:=i+i;
      If (j<htail) and (h[j+1].cost<h[j].cost) Then Inc(j);
      If x.cost<=h[j].cost Then Break;
      h[i]:=h[j]; pos[h[i].point]:=i;
      i:=j;
    End;
    h[i]:=x; pos[x.point]:=i;
  End;

  Procedure Pop(Var point,cost:longint);
  begin
    point:=h[1].point; cost:=h[1].cost;
    pos[point]:=-1;
    h[1]:=h[htail]; pos[h[1].point]:=1;
    Dec(htail);
    Go_Down(1);
  End;

  Procedure Main;
  Var
    i,pp,c,j:longint;
    p:link;
  Begin
    For i:=1 to n Do
    Begin
      h[i].point:=i;
      If i=1 Then h[i].cost:=0 Else h[i].cost:=maxlongint;
      pos[i]:=i;
    End;
    htail:=n;
    ans:=0;
    For pp:=1 to n Do
    Begin
      Pop(i,c); Inc(ans,c);
      p:=a[i];
      While p<>nil Do
      Begin
        j:=p^.data;
        If (pos[j]<>-1) and (p^.cost<h[pos[j]].cost) Then
        Begin
          h[pos[j]].cost:=p^.cost;
          Go_Up(pos[j]);
        End;
        p:=p^.next;
      End;
    End;
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


{
IOI 2003
Day 1 Task Maintain
by Wu Jingyue
}

Program Maintenance;

Const
  maxn=200;

Type
  rtype=Record
    point,cost:longint;
  End;

Var
  a:Array [1..maxn,1..maxn] of longint;
  dep,f:array [1..maxn] of longint;
  edge,n,m,i,j,cost,k,max,mi,mj,ans:longint;

  Function Connected:boolean;
  Var
    q:Array [1..maxn] of longint;
    visit:Array [1..maxn] of boolean;
    head,tail,i,j:longint;
  Begin
    Fillchar(visit,Sizeof(visit),0);
    head:=1; tail:=1; q[1]:=1; visit[1]:=true;
    While head<=tail Do
    Begin
      i:=q[head];
      For j:=1 to n Do
        If not(visit[j]) and (a[i,j]>0) Then
        Begin
          visit[j]:=true;
          Inc(tail); q[tail]:=j;
        End;
      Inc(head);
    End;
    Connected:=(tail=n);
  End;

  Procedure MST;
  Var
    b:Array [1..maxn] of rtype;
    i,j,temp,tot:longint;
    tb:rtype;
  Begin
    Fillchar(f,Sizeof(f),0);
    For i:=1 to n Do
    Begin
      b[i].point:=i;
      If i=1 Then b[i].cost:=0 Else b[i].cost:=maxlongint;
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
        If (temp>0) and (temp<b[j].cost) Then
        Begin
          b[j].cost:=temp;
          f[b[j].point]:=b[i].point;
        End;
      End;
    End;
    Fillchar(a,Sizeof(a),0);
    tot:=0;
    For i:=2 to n Do
    Begin
      j:=b[i].point; Inc(tot,b[i].cost);
      a[j,f[j]]:=b[i].cost; a[f[j],j]:=b[i].cost;
    End;
    Writeln(tot);
  End;

  Function ComputDep(i:longint):longint;
  Begin
    If dep[i]=-1 Then dep[i]:=ComputDep(f[i])+1;
    ComputDep:=dep[i];
  End;

  Procedure GetMax(i,j:longint; Var max,mi,mj:longint);
  Var
    backupi,backupj,k:longint;
  Begin
    max:=0;
    backupi:=i; backupj:=j;
    While dep[i]>dep[j] Do i:=f[i];
    While dep[i]<dep[j] Do j:=f[j];
    While i<>j Do Begin i:=f[i]; j:=f[j] End;
    k:=i;
    i:=backupi; j:=backupj;
    While i<>k Do
    Begin
      If a[i,f[i]]>max Then
      Begin
        max:=a[i,f[i]];
        mi:=f[i]; mj:=i;
      End;
      i:=f[i];
    End;
    While j<>k Do
    Begin
      If a[j,f[j]]>max Then
      Begin
        max:=a[j,f[j]];
        mi:=f[j]; mj:=j;
      End;
      j:=f[j];
    End;
  End;

  Procedure DFS(i:longint);
  Var
    j:longint;
  Begin
    For j:=1 to n Do
      If (j<>f[i]) and (a[i,j]>0) Then
      Begin
        f[j]:=i;
        DFS(j);
      End;
  End;

Begin
  Assign(input,'maintain.in');
  Assign(output,'maintain.out');
  Reset(input);
  Rewrite(output);

  Read(n,m);
  Fillchar(a,Sizeof(a),0);
  For edge:=1 to m Do
  Begin
    Read(i,j,a[i,j]); a[j,i]:=a[i,j];
    If Connected
      Then Begin
        MST;
        Break;
      End
      Else Writeln(-1);
  End;

  While edge<m Do
  Begin
    Inc(edge);
    Read(i,j,cost);
    dep[1]:=0; For k:=2 to n Do dep[k]:=-1;
    For k:=2 to n Do dep[k]:=ComputDep(k);
    GetMax(i,j,max,mi,mj);
    If max>cost Then
    Begin
      a[mi,mj]:=0; a[mj,mi]:=0;
      a[i,j]:=cost; a[j,i]:=cost;
      Fillchar(f,Sizeof(f),0);
      DFS(1);
    End;
    ans:=0;
    For k:=2 to n Do Inc(ans,a[k,f[k]]);
    Writeln(ans);
  End;

  Close(output);
  Close(input);
End.

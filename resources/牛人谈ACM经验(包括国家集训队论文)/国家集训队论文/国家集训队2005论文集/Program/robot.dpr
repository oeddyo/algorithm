program Robot;

const
  maxm=30;
  maxn=100;

type
  ptype=record
    x,y:longint;
  end;
  rtype=record
    point,cost:longint;
  end;

var
  w1,w2:array [1..maxm+1] of ptype;
  p:array [1..maxn] of ptype;
  a:array [1..maxn+2,1..maxn+2] of longint;
  b:array [1..maxn+2] of rtype;
  f,dep:array [1..maxn+2] of longint;
  m,i,n,j,temp,k,ans:longint;
  tb:rtype;

  function min(a,b:longint):longint;
  begin
    if a<b then min:=a else min:=b;
  end;

  function max(a,b:longint):longint;
  begin
    if a>b then max:=a else max:=b;
  end;

  function computdep(i:longint):longint;
  begin
    if dep[i]=-1 then dep[i]:=computdep(f[i])+1;
    computdep:=dep[i];
  end;

begin
  assign(input,'robot.in');
  assign(output,'robot.out');
  reset(input);
  read(m);
  for i:=1 to m+1 do read(w1[i].x,w1[i].y);
  for i:=1 to m+1 do read(w2[i].x,w2[i].y);
  read(n);
  for i:=1 to n do read(p[i].x,p[i].y);
  close(input);

  for i:=1 to n+2 do
    for j:=1 to n+2 do
      a[i,j]:=maxlongint;
  for j:=1 to n do
    for i:=1 to m do
    begin
      if w1[i].x=w1[i+1].x
        then
          if (p[j].y-w1[i].y)*(p[j].y-w1[i+1].y)<=0
            then temp:=abs(w1[i].x-p[j].x)
            else temp:=min(max(abs(p[j].x-w1[i].x),abs(p[j].y-w1[i].y)),max(abs(p[j].x-w1[i+1].x),abs(p[j].y-w1[i+1].y)))
        else
          if (p[j].x-w1[i].x)*(p[j].x-w1[i+1].x)<=0
            then temp:=abs(w1[i].y-p[j].y)
            else temp:=min(max(abs(p[j].x-w1[i].x),abs(p[j].y-w1[i].y)),max(abs(p[j].x-w1[i+1].x),abs(p[j].y-w1[i+1].y)));
      if temp<a[n+1,j] then
      begin
        a[n+1,j]:=temp;
        a[j,n+1]:=temp;
      end;
    end;
  for j:=1 to n do
    for i:=1 to m do
    begin
      if w2[i].x=w2[i+1].x
        then
          if (p[j].y-w2[i].y)*(p[j].y-w2[i+1].y)<=0
            then temp:=abs(w2[i].x-p[j].x)
            else temp:=min(max(abs(p[j].x-w2[i].x),abs(p[j].y-w2[i].y)),max(abs(p[j].x-w2[i+1].x),abs(p[j].y-w2[i+1].y)))
        else
          if (p[j].x-w2[i].x)*(p[j].x-w2[i+1].x)<=0
            then temp:=abs(w2[i].y-p[j].y)
            else temp:=min(max(abs(p[j].x-w2[i].x),abs(p[j].y-w2[i].y)),max(abs(p[j].x-w2[i+1].x),abs(p[j].y-w2[i+1].y)));
      if temp<a[j,n+2] then
      begin
        a[j,n+2]:=temp;
        a[n+2,j]:=temp;
      end;
    end;
  for i:=1 to n do
    for j:=1 to n do
      a[i,j]:=max(abs(p[i].x-p[j].x),abs(p[i].y-p[j].y));

  fillchar(f,sizeof(f),0);
  for i:=1 to n+2 do
  begin
    b[i].point:=i;
    if i=n+1 then b[i].cost:=0 else b[i].cost:=maxlongint;
  end;
  for i:=1 to n+1 do
  begin
    for j:=i+1 to n+2 do
      if b[j].cost<b[i].cost then
      begin
        tb:=b[i]; b[i]:=b[j]; b[j]:=tb;
      end;
    for j:=i+1 to n+2 do
    begin
      temp:=a[b[i].point,b[j].point];
      if temp<b[j].cost then
      begin
        b[j].cost:=temp;
        f[b[j].point]:=b[i].point;
      end;
    end;
  end;

  for i:=1 to n+2 do dep[i]:=-1; dep[n+1]:=0;
  for i:=1 to n+2 do dep[i]:=computdep(i);
  ans:=0;
  i:=n+1; j:=n+2;
  while dep[i]>dep[j] do i:=f[i];
  while dep[i]<dep[j] do j:=f[j];
  while i<>j do
  begin
    i:=f[i]; j:=f[j];
  end;
  k:=i; i:=n+1; j:=n+2;
  while i<>k do
  begin
    if a[i,f[i]]>ans then ans:=a[i,f[i]];
    i:=f[i];
  end;
  while j<>k do
  begin
    if a[j,f[j]]>ans then ans:=a[j,f[j]];
    j:=f[j];
  end;

  rewrite(output);
  writeln(ans);
  close(output);
end.


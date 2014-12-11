PL/SQLで日付フィールドの値は和暦形式へ変換するというファンクションを作成しなさい。
ファンクション：TOWAREKI（パラメータ１、パラメータ２、パラメータ３）
	
パラメータ１：変換する対象
パラメータ２：’R’：略称、’Z’：全称
パラメータ３：変換形式　’YMD’、’YM’、’Y’
					
例：	TOWAREKI（'2011-12-21'、'R'、'YMD'） → H23.12.21					
	TOWAREKI（'2011-12-21'、'Z'、'YMD'） → 平成２３年１２月２１日				
	TOWAREKI（'2011-12-21'、'Z'、'YM'） → 平成２３年１２月
	TOWAREKI（'2011-12-21'、'Z'、'Y'） → 平成２３年
					
明治 45年（ 1月1日 - 7月29日 ） 大正 元年（7月30日 - 12月31日 ）
大正 15年（ 1月1日 - 12月24日 ） 昭和 元年（12月25日 - 12月31日 ）
昭和 64年（ 1月1日 - 1月7日 ） 平成 元年（ 1月8日 - 12月31日 ）

create or replace function TOWAREKI (dt in date, rz char, format varchar2)
return varchar2 is
  ret varchar2(30);
  retFormat varchar2(30);
  rzInvalid EXCEPTION;
  formatInvalid EXCEPTION;
begin
  if (rz not in ('R','Z')) then
    raise rzInvalid;
  end if;
  if (format not in ('YMD','YM','Y')) then
    raise formatInvalid;
  end if;
  -- ret := to_char(dt, 'eeyy/mm/dd hh24:mi:ss','NLS_CALENDAR=''JAPANESE IMPERIAL''');
  
  retFormat := format;  
  if (rz = 'R') then
    retFormat := replace(retFormat, 'Y', 'yy');
    retFormat := replace(retFormat, 'M', '.mm');
    retFormat := replace(retFormat, 'D', '.dd');
    retFormat := 'e' || retFormat;
  end if;
  
  if (rz = 'Z') then
    retFormat := replace(retFormat, 'Y', 'yy/');
    retFormat := replace(retFormat, 'M', 'mm/');
    retFormat := replace(retFormat, 'D', 'dd/');
    retFormat := 'ee' || retFormat;
  end if;
  
  dbms_output.put_line(retFormat);
  
  ret := to_char(dt, retFormat, 'NLS_CALENDAR=''JAPANESE IMPERIAL''');
  
  if (rz = 'Z') then
    ret := regexp_replace(ret, '/', '年', 1, 1);
    ret := regexp_replace(ret, '/', '月', 1, 1);
    ret := regexp_replace(ret, '/', '日', 1, 1);
  end if;
  
  return ret;
  
exception
  when rzInvalid then
    dbms_output.put_line('パラメータ２：’R’：略称、’Z’：全称');
    return null;
  when formatInvalid then
    dbms_output.put_line('パラメータ３：変換形式　’YMD’、’YM’、’Y');
    return null;
  when others then
    return null;
    
end;


-- test
begin
  dbms_output.put_line(TOWAREKI(to_date('2014-12-21','yyyy-mm-dd'),'R','YMD'));
  dbms_output.put_line(TOWAREKI(to_date('2014-12-21','yyyy-mm-dd'),'R','YM'));
  dbms_output.put_line(TOWAREKI(to_date('2014-12-21','yyyy-mm-dd'),'R','Y'));
  dbms_output.put_line(TOWAREKI(to_date('2014-12-21','yyyy-mm-dd'),'Z','YMD'));
  dbms_output.put_line(TOWAREKI(to_date('2014-12-21','yyyy-mm-dd'),'Z','YM'));
  dbms_output.put_line(TOWAREKI(to_date('2014-12-21','yyyy-mm-dd'),'Z','Y'));
end;


-- invalid parameter
begin  
  dbms_output.put_line(TOWAREKI(to_date('2011-12-21','yyyy-mm-dd'),'C','YMD'));
end;

begin
  dbms_output.put_line(TOWAREKI(to_date('2011-12-21','yyyy-mm-dd'),'R','XXX'));
end;


declare
  ch char := 'R';
begin 
  if( ch in ('R','Z')) then
    dbms_output.put_line(ch);
  end if;
  dbms_output.put_lone(to_char(sysdate, 'eeyy/mm/dd', 'NLS_CALENDAR=''JAPANESE IMPERIAL'''));
end;
  
  
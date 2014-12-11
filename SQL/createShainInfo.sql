/*
適用日付<=システム日付
AND　（廃止日付　is　null　or　廃止日付>システム日付）
AND　有効フラグ＝’１’
AND 　訂正連番＝１

TK_DT <= sysdate
and (HS_DT is null or HS_DT > sysdate)
and YK_F = '1'
and TS_RB = 1
*/

select S.KSHA_CD
    , S.STRT_DT
    , S.SHN_CD
    , (MEISHO.FML_NM || nvl(MEISHO.MDL_NM, '') || MEISHO.FST_NM) SHN_NM
    , JOHO.SNGP_DT
    , JOHO.SB_KBN
    , trunc(months_between(sysdate, JOHO.SNGP_DT)/12) NENREI
    , JUSHO.STNS_NM
    , (nvl(JSHO1, '') || nvl(JSHO2, '') || nvl(JSHO3, '')) JUSHO
    , JOHO.GYOMU_SYURUI GM_NY
    , JOHO.GRP_NYUSHA_DT NSHA_YM
    , KAZOKU.TSHA_YM
    , GAKUREKI.STGYP_GKO_NM
    , GAKUREKI.STGYP_YM
    , SHIKAKU.SK_NM
    , SHIKAKU.STK_DT
    , SHOKUREKI.SR_NSHA_YM
    , SHOKUREKI.SR_TSHA_YM
    , SHOKUREKI.SR_GM_NY
from SHAIN S
left outer join SHAIN_MEISHO MEISHO
  on S.KSHA_CD = MEISHO.KSHA_CD
  and S.STRT_DT = MEISHO.STRT_DT
  and S.SHN_CD = MEISHO.SHN_CD
  and MEISHO.TK_DT <= sysdate
  and (MEISHO.HS_DT is null or MEISHO.HS_DT > sysdate)
  and MEISHO.YK_F = '1'
  and MEISHO.TS_RB = 1
left outer join SHAIN_JOHO JOHO
  on S.KSHA_CD = JOHO.KSHA_CD
  and S.STRT_DT = JOHO.STRT_DT
  and S.SHN_CD = JOHO.SHN_CD
  and JOHO.TK_DT <= sysdate
  and (JOHO.HS_DT is null or JOHO.HS_DT > sysdate)
  and JOHO.YK_F = '1'
  and JOHO.TS_RB = 1
left outer join SHAIN_JUSHO JUSHO
  on S.KSHA_CD = JUSHO.KSHA_CD
  and S.STRT_DT = JUSHO.STRT_DT
  and S.SHN_CD = JUSHO.SHN_CD
  and JUSHO.TK_DT <= sysdate
  and (JUSHO.HS_DT is null or JUSHO.HS_DT > sysdate)
  and JUSHO.YK_F = '1'
  and JUSHO.TS_RB = 1
left outer join 
  (select KSHA_CD, STRT_DT, SHN_CD, count(SHN_CD) TSHA_YM
    from SHAIN_KAZOKU
    where TK_DT <= sysdate
    and (HS_DT is null or HS_DT > sysdate)
    and YK_F = '1'
    and TS_RB = 1
    group by KSHA_CD, STRT_DT, SHN_CD
  ) KAZOKU
  on S.KSHA_CD = KAZOKU.KSHA_CD
  and S.STRT_DT = KAZOKU.STRT_DT
  and S.SHN_CD = KAZOKU.SHN_CD
left outer join
  (select KSHA_CD, STRT_DT, SHN_CD
        , GKO_NM STGYP_GKO_NM
        , STGYP_YM
    from SHAIN_GAKUREKI T
    where YK_F = '1'
    and TS_RB = 1
    and (KSHA_CD, STRT_DT, SHN_CD, GKRK_RB) in 
      (select KSHA_CD, STRT_DT, SHN_CD, max(GKRK_RB) 
        from SHAIN_GAKUREKI 
        where YK_F = '1'
        and TS_RB = 1
        group by KSHA_CD, STRT_DT, SHN_CD)
  ) GAKUREKI
  on S.KSHA_CD = GAKUREKI.KSHA_CD
  and S.STRT_DT = GAKUREKI.STRT_DT
  and S.SHN_CD = GAKUREKI.SHN_CD
left outer join
  (select KSHA_CD, STRT_DT, SHN_CD
        , SK_NM
        , STK_DT
    from SHAIN_SHIKAKU T
    where TK_DT <= sysdate
    and (HS_DT is null or HS_DT > sysdate)
    and YK_F = '1'
    and TS_RB = 1
    and (KSHA_CD, STRT_DT, SHN_CD, SK_RB) in
      (select KSHA_CD, STRT_DT, SHN_CD, max(SK_RB) 
        from SHAIN_SHIKAKU 
        where TK_DT <= sysdate
        and (HS_DT is null or HS_DT > sysdate)
        and YK_F = '1'
        and TS_RB = 1
        group by KSHA_CD, STRT_DT, SHN_CD)
  ) SHIKAKU
  on S.KSHA_CD = SHIKAKU.KSHA_CD
  and S.STRT_DT = SHIKAKU.STRT_DT
  and S.SHN_CD = SHIKAKU.SHN_CD
left outer join
  (select KSHA_CD, STRT_DT, SHN_CD
        , KR_KSHA_CD SR_KSHA_CD
        , NSHA_YM SR_NSHA_YM
        , TSHA_YM SR_TSHA_YM
        , GM_NY SR_GM_NY
    from SHAIN_SHOKUREKI T
    where YK_F = '1'
    and TS_RB = 1
    and (KSHA_CD, STRT_DT, SHN_CD, SKRK_RB) in 
      (select KSHA_CD, STRT_DT, SHN_CD, max(SKRK_RB) 
        from SHAIN_SHOKUREKI 
        where YK_F = '1'
        and TS_RB = 1
        group by KSHA_CD, STRT_DT, SHN_CD)
  ) SHOKUREKI
  on S.KSHA_CD = SHOKUREKI.KSHA_CD
  and S.STRT_DT = SHOKUREKI.STRT_DT
  and S.SHN_CD = SHOKUREKI.SHN_CD
where S.TK_DT <= sysdate
  and (S.HS_DT is null or S.HS_DT > sysdate)
  and S.YK_F = '1';


  (select T.KSHA_CD, T.STRT_DT, T.SHN_CD
        , T.SK_NM
        , T.STK_DT
    from SHAIN_SHIKAKU T inner join
      (select KSHA_CD, STRT_DT, SHN_CD, max(SK_RB) MAX_SK_RB 
        from SHAIN_SHIKAKU 
        where TK_DT <= sysdate
        and (HS_DT is null or HS_DT > sysdate)
        and YK_F = '1'
        and TS_RB = 1
        group by KSHA_CD, STRT_DT, SHN_CD) M
      on T.KSHA_CD = M.KSHA_CD
      and T.STRT_DT = M.STRT_DT
      and T.SHN_CD = M.SHN_CD
      and T.SK_RB = M.MAX_SK_RB
    where T.TK_DT <= sysdate
      and (T.HS_DT is null or T.HS_DT > sysdate)
      and T.YK_F = '1'
      and T.TS_RB = 1
  ) SHIKAKU

  (select KSHA_CD, STRT_DT, SHN_CD
        , KR_KSHA_CD SR_KSHA_CD
        , NSHA_YM SR_NSHA_YM
        , TSHA_YM SR_TSHA_YM
        , GM_NY SR_GM_NY
    from SHAIN_SHOKUREKI T
    where YK_F = '1'
    and TS_RB = 1
    and exists
      (select KSHA_CD, STRT_DT, SHN_CD, max(SKRK_RB) 
        from SHAIN_SHOKUREKI M
        where YK_F = '1'
        and TS_RB = 1
        group by KSHA_CD, STRT_DT, SHN_CD
        having M.KSHA_CD = T.KSHA_CD
        and M.STRT_DT = T.STRT_DT
        and M.SHN_CD = T.SHN_CD
        and T.SKRK_RB = max(SKRK_RB))
   ) SHOKUREKI

/*
PL/SQLで社員個人情報データ作成というプロシージャを作成しなさい。
プロシージャ：createShainInfo（）
正常の場合、取込件数と登録件数の情報を出力する
例外の場合、エラーメッセージを出力する
*/

begin
  createShainInfo();
end;

create or replace procedure createShainInfo
is
--declare
  LOG_PROC_NAME varchar2(40);

  cursor kojinCur is
    select S.KSHA_CD
        , S.STRT_DT
        , S.SHN_CD
        , (MEISHO.FML_NM || nvl(MEISHO.MDL_NM, '') || MEISHO.FST_NM) SHN_NM
        , JOHO.SNGP_DT
        , JOHO.SB_KBN SEX_NM
        , trunc(months_between(sysdate, JOHO.SNGP_DT)/12) NENREI
        , JUSHO.STNS_NM
        , (nvl(JSHO1, '') || nvl(JSHO2, '') || nvl(JSHO3, '')) JUSHO
        , JOHO.GYOMU_SYURUI GM_NY
        , JOHO.GRP_NYUSHA_DT NSHA_YM
        , KAZOKU.TSHA_YM
        , GAKUREKI.STGYP_GKO_NM
        , GAKUREKI.STGYP_YM
        , SHIKAKU.SK_NM
        , SHIKAKU.STK_DT
        , SHOKUREKI.SR_KSHA_CD
        , SHOKUREKI.SR_NSHA_YM
        , SHOKUREKI.SR_TSHA_YM
        , SHOKUREKI.SR_GM_NY
    from SHAIN S
    left outer join SHAIN_MEISHO MEISHO
      on S.KSHA_CD = MEISHO.KSHA_CD
      and S.STRT_DT = MEISHO.STRT_DT
      and S.SHN_CD = MEISHO.SHN_CD
      and MEISHO.TK_DT <= sysdate
      and (MEISHO.HS_DT is null or MEISHO.HS_DT > sysdate)
      and MEISHO.YK_F = '1'
      and MEISHO.TS_RB = 1
    left outer join SHAIN_JOHO JOHO
      on S.KSHA_CD = JOHO.KSHA_CD
      and S.STRT_DT = JOHO.STRT_DT
      and S.SHN_CD = JOHO.SHN_CD
      and JOHO.TK_DT <= sysdate
      and (JOHO.HS_DT is null or JOHO.HS_DT > sysdate)
      and JOHO.YK_F = '1'
      and JOHO.TS_RB = 1
    left outer join SHAIN_JUSHO JUSHO
      on S.KSHA_CD = JUSHO.KSHA_CD
      and S.STRT_DT = JUSHO.STRT_DT
      and S.SHN_CD = JUSHO.SHN_CD
      and JUSHO.TK_DT <= sysdate
      and (JUSHO.HS_DT is null or JUSHO.HS_DT > sysdate)
      and JUSHO.YK_F = '1'
      and JUSHO.TS_RB = 1
    left outer join 
      (select KSHA_CD, STRT_DT, SHN_CD, count(SHN_CD) TSHA_YM
        from SHAIN_KAZOKU
        where TK_DT <= sysdate
        and (HS_DT is null or HS_DT > sysdate)
        and YK_F = '1'
        and TS_RB = 1
        group by KSHA_CD, STRT_DT, SHN_CD
      ) KAZOKU
      on S.KSHA_CD = KAZOKU.KSHA_CD
      and S.STRT_DT = KAZOKU.STRT_DT
      and S.SHN_CD = KAZOKU.SHN_CD
    left outer join
      (select KSHA_CD, STRT_DT, SHN_CD
            , GKO_NM STGYP_GKO_NM
            , STGYP_YM
        from SHAIN_GAKUREKI T
        where YK_F = '1'
        and TS_RB = 1
        and (KSHA_CD, STRT_DT, SHN_CD, GKRK_RB) in 
          (select KSHA_CD, STRT_DT, SHN_CD, max(GKRK_RB) 
            from SHAIN_GAKUREKI 
            where YK_F = '1'
            and TS_RB = 1
            group by KSHA_CD, STRT_DT, SHN_CD)
      ) GAKUREKI
      on S.KSHA_CD = GAKUREKI.KSHA_CD
      and S.STRT_DT = GAKUREKI.STRT_DT
      and S.SHN_CD = GAKUREKI.SHN_CD
    left outer join
      (select KSHA_CD, STRT_DT, SHN_CD
            , SK_NM
            , STK_DT
        from SHAIN_SHIKAKU T
        where TK_DT <= sysdate
        and (HS_DT is null or HS_DT > sysdate)
        and YK_F = '1'
        and TS_RB = 1
        and (KSHA_CD, STRT_DT, SHN_CD, SK_RB) in
          (select KSHA_CD, STRT_DT, SHN_CD, max(SK_RB) 
            from SHAIN_SHIKAKU 
            where TK_DT <= sysdate
            and (HS_DT is null or HS_DT > sysdate)
            and YK_F = '1'
            and TS_RB = 1
            group by KSHA_CD, STRT_DT, SHN_CD)
      ) SHIKAKU
      on S.KSHA_CD = SHIKAKU.KSHA_CD
      and S.STRT_DT = SHIKAKU.STRT_DT
      and S.SHN_CD = SHIKAKU.SHN_CD
    left outer join
      (select KSHA_CD, STRT_DT, SHN_CD
            , KR_KSHA_CD SR_KSHA_CD
            , NSHA_YM SR_NSHA_YM
            , TSHA_YM SR_TSHA_YM
            , GM_NY SR_GM_NY
        from SHAIN_SHOKUREKI T
        where YK_F = '1'
        and TS_RB = 1
        and (KSHA_CD, STRT_DT, SHN_CD, SKRK_RB) in 
          (select KSHA_CD, STRT_DT, SHN_CD, max(SKRK_RB) 
            from SHAIN_SHOKUREKI 
            where YK_F = '1'
            and TS_RB = 1
            group by KSHA_CD, STRT_DT, SHN_CD)
      ) SHOKUREKI
      on S.KSHA_CD = SHOKUREKI.KSHA_CD
      and S.STRT_DT = SHOKUREKI.STRT_DT
      and S.SHN_CD = SHOKUREKI.SHN_CD
    where S.TK_DT <= sysdate
      and (S.HS_DT is null or S.HS_DT > sysdate)
      and S.YK_F = '1';
      
  kojinRow kojinCur%rowtype;
  insertCount integer := 0;
  updateCount integer := 0;
  readCount integer := 0;
  logFilename varchar(20) := 'wukejia.log';
  lstart number;
  lend number;
  ldiff number;
  
begin 
  LOG_PROC_NAME := '[' || $$PLSQL_UNIT || '] ';
  lstart := dbms_utility.get_time;
  
  open kojinCur;
  
  loop
    fetch kojinCur into kojinRow;
    exit when kojinCur%notfound;
    readCount := readCount + 1;
    
    dbms_output.put_line(kojinRow.KSHA_CD || ' ' || kojinRow.STRT_DT  || ' ' 
      || kojinRow.SHN_CD || ' ' || kojinRow.SHN_NM );
    
    -- (KSHA_CD,STRT_DT,SHN_CD)レコードが存在すればupdateする
    update SHAIN_KOJIN 
    set KSHA_CD = kojinRow.KSHA_CD
      , STRT_DT = kojinRow.STRT_DT
      , SHN_CD = kojinRow.SHN_CD
      , SHN_NM = kojinRow.SHN_NM
      , SNGP_DT = kojinRow.SNGP_DT
      , SEX_NM = kojinRow.SEX_NM
      , NENREI = kojinRow.NENREI
      , STNS_NM = kojinRow.STNS_NM
      , JUSHO = kojinRow.JUSHO
      , GM_NY = kojinRow.GM_NY
      , NSHA_YM = kojinRow.NSHA_YM
      , TSHA_YM = kojinRow.TSHA_YM
      , STGYP_GKO_NM = kojinRow.STGYP_GKO_NM
      , STGYP_YM = kojinRow.STGYP_YM
      , SK_NM = kojinRow.SK_NM
      , STK_DT = kojinRow.STK_DT
      , SR_KSHA_CD = kojinRow.SR_KSHA_CD
      , SR_NSHA_YM = kojinRow.SR_NSHA_YM
      , SR_TSHA_YM = kojinRow.SR_TSHA_YM
      , SR_GM_NY = kojinRow.SR_GM_NY
    where KSHA_CD = kojinRow.KSHA_CD 
      and STRT_DT = kojinRow.STRT_DT 
      and SHN_CD = kojinRow.SHN_CD;
        
    -- レコードが存在しなければinsert
    if sql%notfound then
      insert into SHAIN_KOJIN 
            ( KSHA_CD
            , STRT_DT
            , SHN_CD
            , SHN_NM
            , SNGP_DT
            , SEX_NM
            , NENREI
            , STNS_NM
            , JUSHO
            , GM_NY
            , NSHA_YM
            , TSHA_YM
            , STGYP_GKO_NM
            , STGYP_YM
            , SK_NM
            , STK_DT
            , SR_KSHA_CD
            , SR_NSHA_YM
            , SR_TSHA_YM
            , SR_GM_NY)
      values (kojinRow.KSHA_CD
            , kojinRow.STRT_DT
            , kojinRow.SHN_CD
            , kojinRow.SHN_NM
            , kojinRow.SNGP_DT
            , kojinRow.SEX_NM
            , kojinRow.NENREI
            , kojinRow.STNS_NM
            , kojinRow.JUSHO
            , kojinRow.GM_NY
            , kojinRow.NSHA_YM
            , kojinRow.TSHA_YM
            , kojinRow.STGYP_GKO_NM
            , kojinRow.STGYP_YM
            , kojinRow.SK_NM
            , kojinRow.STK_DT
            , kojinRow.SR_KSHA_CD
            , kojinRow.SR_NSHA_YM
            , kojinRow.SR_TSHA_YM
            , kojinRow.SR_GM_NY);
            
      insertCount := insertCount + 1;
    else
      updateCount := updateCount + 1;
    end if;
    
    if (mod(readCount, 1000) = 0) then
      commit;
    end if;
    
  end loop;
  
  close kojinCur;
  commit;
  
  lend := dbms_utility.get_time;
  ldiff := (lend-lstart)/100;
  
  dbms_output.put_line( LOG_PROC_NAME || '取込件数: ' || readCount || '件');
  dbms_output.put_line( LOG_PROC_NAME || '処理件数: ' || (insertCount + updateCount) || '件' 
    || ' (挿入' || insertCount || '件, 更新' || updateCount || '件' || ')');
  dbms_output.put_line( LOG_PROC_NAME || '処理時間: ' || ldiff || 's');
  
--   Logger(logFilename, LOG_PROC_NAME || '取込件数: ' || readCount || '件');
--   Logger(logFilename, LOG_PROC_NAME || '処理件数: ' || (insertCount + updateCount) || '件' 
--      || ' (挿入' || insertCount || '件, 更新' || updateCount || '件' || ')');

  LogUtility.putLog(LOG_PROC_NAME || '取込件数: ' || readCount || '件');
  LogUtility.putLog(LOG_PROC_NAME || '処理件数: ' || (insertCount + updateCount) || '件' 
      || ' (挿入' || insertCount || '件, 更新' || updateCount || '件' || ')');
  LogUtility.putLog( LOG_PROC_NAME || '処理時間: ' || ldiff || 's');
  LogUtility.writeLog(logFilename);
    
  
exception
  when others then
    rollback;
    -- dbms_output.put_line(sqlerrm(sqlcode));
    dbms_output.put_line(LOG_PROC_NAME || '取込件数: ' || readCount || '件');
    dbms_output.put_line(LOG_PROC_NAME || '処理件数: ' || (insertCount + updateCount) || '件' 
      || ' (挿入' || insertCount || '件, 更新' || updateCount || '件' || ')');
    dbms_output.put_line(dbms_utility.format_error_stack);
    
    LogUtility.putLog(LOG_PROC_NAME || '取込件数: ' || readCount || '件');
    LogUtility.putLog(LOG_PROC_NAME || '処理件数: ' || (insertCount + updateCount) || '件' 
      || ' (挿入' || insertCount || '件, 更新' || updateCount || '件' || ')');
    LogUtility.putLog(dbms_utility.format_error_stack);
    LogUtility.writeLog(logFilename);
    
--     Logger(logFilename, LOG_PROC_NAME || '取込件数: ' || readCount || '件');
--     Logger(logFilename, LOG_PROC_NAME || '処理件数: ' || (insertCount + updateCount) || '件' 
--      || ' (挿入' || insertCount || '件, 更新' || updateCount || '件' || ')');
--     Logger(logFilename, dbms_utility.format_error_stack);
end;

------------------------- end createShainInfo ------------------------

select mod(12, 5) from dual;

declare
  LOG_PROC_NAME varchar2(40);
begin
  LOG_PROC_NAME := '[' || $$PLSQL_UNIT || '] ';
  dbms_output.put_line(LOG_PROC_NAME);
end;

begin 
  for kojinRow in kojinCur loop
    update SHAIN_KOJIN 
    set row = kojinRow 
    where KSHA_CD = kojinRow.KSHA_CD 
      and STRT_DT = kojinRow.STRT_DT 
      and SHN_CD = kojinRow.SHN_CD;
  
    if sql%notfound then
      insert into SHAIN_KOJIN values kojinRow;
    end if;
  end loop;
end;




create or replace procedure createShainInfo
is
  cursor shainCur is 
    select KSHA_CD, STRT_DT, SHN_CD 
    from SHAIN 
    where TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1';
  shainRow SHAIN%rowtype;
  
  cursor meishoCur (kcd varchar2, sdt date, scd varchar2) is
    select (FML_NM || nvl(MDL_NM, '') || FST_NM) SHN_NM
    from SHAIN_MEISHO 
    where KSHA_CD = kcd 
      and STRT_DT = sdt 
      and SHN_CD = scd
      and TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1';
  meishoRec meishoCur%rowtype;
  
  cursor johoCur (kcd varchar2, sdt date, scd varchar2) is
    select SNGP_DT, SB_KBN, trunc(months_between(sysdate, SNGP_DT)/12) NENREI
    from SHAIN_JOHO 
    where KSHA_CD = kcd 
      and STRT_DT = sdt 
      and SHN_CD = scd
      and TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1'
      and TS_RB = 1;
  johoRec johoCur%rowtype;
  
  kojinRow SHAIN_KOJIN%rowtype;
begin
  
  for shainRow in shainCur loop
    kojinRow.KSHA_CD := shainRow.KSHA_CD;
    kojinRow.STRT_DT := shainRow.STRT_DT;
    kojinRow.SHN_CD := shainRow.SHN_CD;
    
    open meishoCur(kojinRow.KSHA_CD, kojinRow.STRT_DT, kojinRow.SHN_CD);
    fetch meishoCur into meishoRec;
    if meishoCur%found then
      kojinRow.SHN_NM := meishoRec.SHN_NM;
    else
      kojinRow.SHN_NM := null;
    end if;
    close meishoCur;
    
    open johoCur(kojinRow.KSHA_CD, kojinRow.STRT_DT, kojinRow.SHN_CD);
    fetch johoCur into johoRec;
    if johoCur%found then
	  kojinRow.SNGP_DT := johoRec.SNGP_DT;
      kojinRow.SEX_NM := johoRec.SB_KBN;
      kojinRow.NENREI := johoRec.NENREI;
    else
	  kojinRow.SNGP_DT := null;
      kojinRow.SEX_NM := null;
      kojinRow.NENREI := null;
    end if;
    close johoCur;
    
    dbms_output.put_line(kojinRow.KSHA_CD || ' ' || kojinRow.STRT_DT  || ' ' 
      || kojinRow.SHN_CD || ' ' || kojinRow.SHN_NM || ' ' || kojinRow.SNGP_DT
      || ' ' || kojinRow.SEX_NM || ' ' || kojinRow.NENREI);
	
    update SHAIN_KOJIN 
    set row = kojinRow 
    where KSHA_CD = kojinRow.KSHA_CD 
      and STRT_DT = kojinRow.STRT_DT 
      and SHN_CD = kojinRow.SHN_CD;
  
    if sql%notfound then
      insert into SHAIN_KOJIN values kojinRow;
    end if;    
  end loop;
  
end;

begin
  createShainInfo();
end;


declare
  cursor shainCur is 
    (select * from SHAIN where TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1');
  shainRow SHAIN%rowtype;
  kojinRow SHAIN_KOJIN%rowtype;
begin
  for shainRow in shainCur loop
    kojinRow.KSHA_CD := shainRow.KSHA_CD;
    kojinRow.STRT_DT := shainRow.STRT_DT;
    kojinRow.SHN_CD := shainRow.SHN_CD;
    
    dbms_output.put_line(shainRow.KSHA_CD || ' ' || shainRow.STRT_DT || ' ' || shainRow.SHN_CD);
  end loop;
end;

declare
  cursor shainCur is 
    select KSHA_CD, STRT_DT, SHN_CD 
    from SHAIN 
    where TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1';
  cursor meishoCur (kcd varchar2, sdt date, scd varchar2) is
    select (FML_NM || nvl(MDL_NM, '') || FST_NM) SHN_NM
    from SHAIN_MEISHO 
    where KSHA_CD = kcd 
      and STRT_DT = sdt 
      and SHN_CD = scd
      and TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1';
  meishoRec meishoCur%rowtype;
  
  cursor johoCur (kcd varchar2, sdt date, scd varchar2) is
    select SNGP_DT, SB_KBN, trunc(months_between(sysdate, SNGP_DT)/12) NENREI
    from SHAIN_JOHO 
    where KSHA_CD = kcd 
      and STRT_DT = sdt 
      and SHN_CD = scd
      and TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1'
      and TS_RB = 1;
  johoRec johoCur%rowtype;
  
  shainRow SHAIN%rowtype;
  kojinRow SHAIN_KOJIN%rowtype;
begin

  for shainRow in shainCur loop
    kojinRow.KSHA_CD := shainRow.KSHA_CD;
    kojinRow.STRT_DT := shainRow.STRT_DT;
    kojinRow.SHN_CD := shainRow.SHN_CD;
    
    open meishoCur(kojinRow.KSHA_CD, kojinRow.STRT_DT, kojinRow.SHN_CD);
    fetch meishoCur into meishoRec;
    if meishoCur%found then
      kojinRow.SHN_NM := meishoRec.SHN_NM;
    else
      kojinRow.SHN_NM := null;
    end if;
    close meishoCur;
    
	open johoCur(kojinRow.KSHA_CD, kojinRow.STRT_DT, kojinRow.SHN_CD);
    fetch johoCur into johoRec;
    if johoCur%found then
	  kojinRow.SNGP_DT := johoRec.SNGP_DT;
      kojinRow.SEX_NM := johoRec.SB_KBN;
      kojinRow.NENREI := johoRec.NENREI;
    else
	  kojinRow.SNGP_DT := null;
      kojinRow.SEX_NM := null;
      kojinRow.NENREI := null;
    end if;
    close johoCur;
	
    dbms_output.put_line(kojinRow.KSHA_CD || ' ' || kojinRow.STRT_DT  || ' ' 
      || kojinRow.SHN_CD || ' ' || kojinRow.SHN_NM || ' ' || kojinRow.SNGP_DT
      || ' ' || kojinRow.SEX_NM || ' ' || kojinRow.NENREI);
	  
  end loop;
end;

select * from SHAIN where TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1'

select KSHA_CD,STRT_DT,SHN_CD, (FML_NM || nvl(MDL_NM, '') || FST_NM) from SHAIN_MEISHO 
    where TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1';


select KSHA_CD,STRT_DT,SHN_CD, (FML_NM || nvl(MDL_NM, '') || FST_NM) from SHAIN_MEISHO 
    where KSHA_CD = 'K001'
      and STRT_DT = to_date('13-11-19','YY-MM-DD')
      and SHN_CD = 'S002'
      and TK_DT <= sysdate
      and (HS_DT is null or HS_DT > sysdate)
      and YK_F = '1';

begin;
  open meishoCur('K001', to_date('13-11-19','YY-MM-DD'), 'S001');
  fetch meishoCur into meishoRec;
  if meishoCur%found then
    dbms_output.put_line(meishoRec.SHN_NM);
  end if;
  close meishoCur;
end;


begin
  dbms_output.put_line(sqlerrm(SQLCODE));
end;

begin
  raise NO_DATA_FOUND;
exception
  when no_data_found then
    dbms_output.put_line(dbms_utility.format_error_stack);
end;

SELECT a.*,
concat((a.zz-b.zz)/b.zz*100, "%")
AS '年度利润比'
FROM yrprofit as a LEFT JOIN
yrprofit as b
ON a.year=b.year+1;

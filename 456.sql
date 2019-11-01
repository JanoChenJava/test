/*SELECT ename
FROM emp
WHERE sal>ALL(SELECT sal 
	FROM emp WHERE deptno=30);*/

SELECT ename,sal,dept.dname
FROM emp LEFT JOIN dept
ON emp.deptno=dept.deptno
WHERE sal>(SELECT MAX(sal)
	FROM emp WHERE deptno=30);
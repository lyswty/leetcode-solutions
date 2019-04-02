# Write your MySQL query statement below
select d.Name as Department, e.Name as Employee, e.Salary from Employee e, Department d where e.DepartmentId=d.Id and (select count(distinct salary) from Employee where Salary>e.Salary and DepartmentId=e.DepartmentId)<3 order by e.DepartmentId, Salary desc

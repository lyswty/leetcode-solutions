# Write your MySQL query statement below
select Name Customers from Customers where id not in (select distinct Customerid from Orders)

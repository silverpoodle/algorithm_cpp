select distinct id, email, first_name, last_name
from developers d
join skillcodes s
on s.code = d.skill_code&s.code
and s.category like 'Front End'
order by d.id
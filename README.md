**Overview:**
This project is a Project Management Tool implemented in C++. It allows users to create, view, and manage multiple projects by tracking their start/end dates, available funds, resources (manpower and equipment), and profits. The tool includes features like sorting projects by profit, selecting projects based on finish time, and calculating the overall profit for a set of selected projects.

**Features**
Create Project:
Input project details (name, start/end date, manpower, equipment, and fund). Automatically calculates the profit based on available resources and fund.

Display Projects:
View all created projects with their respective details, including start/end dates, manpower, equipment, and profit.

Display Projects Sorted by Profit:
Sort and display projects in descending order of their profit.

Select Projects Based on Finish Time:
Select and display projects based on their finish time (earliest finish first), ensuring no project overlaps with another.

Profit Calculation:
For each project, the profit is calculated using the formula:
Profit=Fund−(Manpower×Cost per Manpower)−(Equipment×Cost per Equipment)
Profit=Fund−(Manpower×Cost per Manpower)−(Equipment×Cost per Equipment)
Cost per Manpower: $100
Cost per Equipment: $1000

**Conclusion:**
This project management tool offers an easy-to-use interface to manage multiple projects, track resources, and calculate profits. It’s a great starting point for more complex project management software and can be enhanced with additional features such as dynamic resource allocation and budget forecasting.

**Future Improvements:**
• Add file input/output for persistent project storage.
• Include more complex algorithms for project selection based on multiple criteria (e.g., priority, deadline).
• Enhance the UI and include error handling for invalid inputs.

 
 

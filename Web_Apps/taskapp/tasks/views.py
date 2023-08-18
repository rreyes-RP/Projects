from django.shortcuts import render, get_object_or_404
from .models import Task

def task_list(request):
    tasks = Task.objects.all() # Retrieve all tasks from the database
    return render(request, 'tasks/task_list.html', {'tasks': tasks})

def task_detail(request, task_id):
    task = get_object_or_404(Task, pk=task_id) # Retrieve a specific task or show a 404 error
    return render(request, 'tasks/task_detail.html', {'tasks': task})




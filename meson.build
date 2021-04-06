project('ceres', 'cpp')
project_sources = []

inc_dir = include_directories('include')

# Sources
project_sources += files('src/main.cpp')
project_sources += files('src/lexer/lexer.cpp')
project_sources += files('src/error.cpp')

executable('ceres', project_sources, include_directories : inc_dir)

CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

PROJECT(tabulators)

SET(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets)

qt5_wrap_ui(UI_HEADERS
	ui/dialog.ui
	ui/tabulator.ui
)

qt5_add_resources(QT_RESOURCES assets/assets.qrc)

ADD_EXECUTABLE(tabulators
    src/main.cpp
	src/tabulators.cpp
	src/dialog.cpp
	src/tabulator.cpp
	${UI_HEADERS}
    ${QT_RESOURCES}
)

target_link_libraries(tabulators
    Qt5::Widgets
)

from conan import ConanFile

class Buzvis(ConanFile):
    generators = ("CMakeDeps", "CMakeToolchain")
    settings = ("os", "build_type", "arch", "compiler")


def requirements (self):
    self.requires("fmt/10.1.1")
    self.requires("qt/[>=6.5 <6.6]")

def build_requirements(self):
    self.tool_requires("cmake/[>=3.28]")

def configure(self):
    self.options["qt/*"].shared = False
    self.options["qt/*"].qtmultimedia = True

def layout(self):
    self.folders.generators = ""




# [requires]
# fmt/8.0.1

# [generators]
# CMakeDeps
# CMakeToolchain

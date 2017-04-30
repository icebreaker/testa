solution 'testa'
	configurations { 'release' }

	location 'build'
	objdir 'build'
	targetdir 'build'

	if _ACTION == 'clean' then
		os.rmdir('build')
	end

	project 'sample'
		language 'C'
		kind 'ConsoleApp'
		includedirs { 'src' }
		files { 'src/sample/*.c' }

		configuration "gmake"
			buildoptions { "-ansi", "-pedantic", "-Wall", "-Wextra", "-Werror" }

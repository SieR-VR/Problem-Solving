if (!process.argv || process.argv.length !== 3) {
    console.log('Usage: node bundle.js <file>');
    process.exit(1);
}

const GLOBAL_INCLUDE_MATCH = /\#include \"includes\/([\d\w]+)\.h\"/g;
const [node, script, file] = process.argv;

const path = require('path');
const fs = require('fs');

const fileName = path.resolve(process.cwd(), file);
let fileContent = fs.readFileSync(fileName, 'utf8');

const matchedIterator = fileContent.matchAll(GLOBAL_INCLUDE_MATCH)

let result = matchedIterator.next();
while (!result.done) {
    const [fullMatchLine, includeName] = result.value;
    const includeFileName = path.resolve(process.cwd(), `includes/${includeName}.h`);
    const includeFileContent = fs.readFileSync(includeFileName, 'utf8');

    fileContent = fileContent.replace(
        fullMatchLine,
        `// includes/${includeName}.h\n` +
        includeFileContent
            .split('\n')
            .filter(line => !line.startsWith('#include'))
            .join('\n')
    );

    result = matchedIterator.next();
}

console.log(fileContent);
process.exit(0);

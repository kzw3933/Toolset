import inquirer from "inquirer";
import fs from "node:fs/promises";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";
import { parseArgs } from "node:util";

const __dirname = dirname(fileURLToPath(import.meta.url));
const dataFile = join(__dirname, "data.json");

var allPackageLoaded =  !!inquirer && !!fs && !!fileURLToPath && !!dirname && !!join &&!!parseArgs;
if(! allPackageLoaded) {
    console.log("Please ensure all packages (inquirer fs fileURLToPath dirname join parseArgs) can be loaded");
    process.exit(1);
} 

const options = {
    add: {
        type: "boolean",
        short: "a",
    },
}

const {
    values: { add },
} = parseArgs({ options });


if(add) {
    addQuestion();
} else {
    askQuestion();
}

async function askQuestion() {

    const data = await fs.readFile(dataFile)
    const parsedData = JSON.parse(data.toString())

    if(parsedData.length === 0) {
        console.log("You don't have any knowledege stored yet");
        return ;
    }

    const target = parsedData[Math.floor(Math.random()*parsedData.length)];
    
    const { question, answer } = target;

    const answers = await inquirer.prompt([
        {
            type: "input",
            name: "useranswer",
            message: question
        },
    ]);
    target.lastAnsweredCorrect = checkAnswer(answers.username, answer);
    target.lastAsked = Date.now().toString();

    const newData = parsedData.filter(item => item.id !== target.id)
    newData.push(target);
    await fs.writeFile(dataFile, JSON.stringify(newData));
}

async function checkAnswer(input, answer) {
    console.log(`You answered: ${input}.`);
    console.log(`The actual answer is: ${answer}`);
    const response = await inquirer.prompt([
        {
            message: "Did you get it right?",
            type: "confirm",
            name: "check",
        }
    ])

    console.log(response);
    return response.check;
}

async function addQuestion() {
    console.log("Hello, let's add a new question.");
    const responses = await inquirer.prompt([
        {type: "input", name: "targetquestion", message:"What is your question? "},
        {type: "input", name: "targetanswer", message:"What is the answer? "}
    ]);
    console.log(responses);
    const data = await fs.readFile(dataFile);
    const parsedData = JSON.parse(data.toString())

    parsedData.push({
        id: getId(parsedData),
        question: responses.targetquestion,
        answer: responses.targetanswer
    })

    await fs.writeFile(dataFile, JSON.stringify(parsedData))

}

function getId(data) {
    return Math.max(...data.map((item) => item.id))+1;
}




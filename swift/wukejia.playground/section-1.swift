import Foundation

// Challenge 10 – Bloginator (use Xcode6-Beta6)

/**
R1 – Create a constant array of String literals called “types” with the
values: technology, memes, cat videos
**/
// implement code for R1 below
let types = ["technology", "memes", "cat videos"]
//println(types)


/**
R2 – Create a BlogPost class with the following properties:

1. type – String, constant. A random value from the types
array. (Hint: you can use arc4random_uniform to randomly select a value.)
2. views – Optional Int. Set to nil.
3. author – String
4. email – String
5. order – Int. Set to zero.

Create an initializer to set the author’s name (the author property) and email property. Create a “teaser”
method that returns a String with the author’s name and number of views:
“Mike Smith has 5 views for this blog post”. If views are nil,
return “No one has read your blog post yet. Pity.”.
**/
// implement code for R2 below
class BlogPost {
    let type: String = types[Int(arc4random_uniform(UInt32(types.count)))]
    var views: Int? = nil
    var author: String
    var email: String
    var order: Int = 0
    
    init(name: String, email: String){
        self.author = name
        self.email = email
    }
    
    func teaser() -> String {
        if (views != nil) {
            return "\(author) has \(views!) views for this blog post"
        } else {
            return "No one has read your blog post yet. Pity."
        }
    }
    
}
//let post = BlogPost(name: "Kejia.Wu", email: "kejiawu@example.com")
//println(post.teaser())
//post.views = 5
//println(post.teaser())


/**
R3 – Create a “randomAuthor” function that returns a tuple. Then create
an “Author” struct with a “name” and “email” property. Add 5 Author structs
to a dictionary using the author’s name as the key. This function returns
a randomly selected name and email of an Author from the dictionary.
**/
// implement code for R3 below
func randomAuthor(dict: [String: String]) -> (String, String) {
    if (dict.count == 0) {
        return ("", "")
    }
    var rand = Int(arc4random_uniform(UInt32(dict.count)))
    for (k, v) in dict {
        if (rand == 0){
            return (k, v)
        }
        rand -= 1
    }
    return ("","")
}
struct Author {
    var name, email: String
}
let authors = [
    Author(name: "Kejia.Wu", email: "kejiawu@example.com"),
    Author(name: "Peter.Burg", email: "peterburg@example.com"),
    Author(name: "Cyan", email: "cyan@example.com"),
    Author(name: "Kimi", email: "Kimi@example.com"),
    Author(name: "Jiong", email: "jiong@example.com")
    ]

var authorDict = [String: String]()
for author in authors {
    authorDict[author.name] = author.email
}

//for i in 1...10 {
//    var author = randomAuthor(authorDict)
//    println(author)
//}


/**
R4 – Create an array of 10 blog posts with a for loop. Set the “author”
property to the value returned from “randomAuthor” function and set
the “order” property to the value of the index of the for loop used to
populate this array.
**/
// implement code for R4 below
var blogPosts = [BlogPost]()
for i in 0..<10 {
    var author = randomAuthor(authorDict)
    var blogPost = BlogPost(name: author.0, email: author.1)
    blogPost.order = i
    blogPosts.append(blogPost)
    
//    print(blogPosts[i].order)
//    println(blogPosts[i].author)
}


/**
R5 – Create a “randomViews” function that accepts the “type” of blog post
for an input. Create an array literal of Ints (these are the possible view
counts) with the values: 10, 20, 30, 40, 50. Select a random value from
this possible view count array and create a switch that returns nil if
the views are 10, 0 if the views are either 20 or 30, else return the randomly
selected number of views. If the “type” passed to the function is
“cat videos” always return nil.
**/
// implement code for R5 below
func randomViews(type: String) -> Int? {
    if (type == "cat videos"){
        return nil
    }
    let possibleViewCounts = [10, 20, 30, 40, 50]
    var randValue = possibleViewCounts[Int(arc4random_uniform(UInt32(possibleViewCounts.count)))]
    
    switch randValue {
    case 10:
        return nil
    case 20, 30:
        return 0
    default:
        return randValue
    }
}


/**
R6 – Iterate the array of blog posts, generate a value from “randomViews” function
for each one and set it to the blog post “views” property. Then println the
value of each post.teaser().
**/
// implement code for R6 below
for blogPost in blogPosts {
    blogPost.views = randomViews(blogPost.type)
    println(blogPost.teaser())
}


/**
R7 – Write a simple stack using a struct with Generics
that has three methods. It should push and pop BlogPosts and also
returns the current count of BlogPosts. Iterate the array of blog posts
and push each one onto the “blogs” stack. Println the count of items in
the stack. Use a for loop to iterate the “blogs” stack, pop the top one
off and println the blog’s teaser. Println the count of items in the stack.
**/
// implement code for R7 below
struct Stack<T> {
    var items = [T]()
    mutating func push(item: T){
        items.append(item)
    }
    
    mutating func pop() -> T {
        return items.removeLast()
    }
    
    mutating func count() -> Int{
        return items.count
    }
}

var blogStack = Stack<BlogPost>()
for blogPost in blogPosts {
    blogStack.push(blogPost)
}
println(blogStack.count())

for i in 0..<blogStack.count() {
    var blogPost = blogStack.pop()
    println(blogPost.teaser())
}
println(blogStack.count())
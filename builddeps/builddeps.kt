import java.util.*

fun main() {
    val lines = generateSequence { readLine() }.toList()

    // inputs
    val N = lines[0].toInt()

    val graph = mutableMapOf<String, List<String>>()
    for (i in 1 until N + 1) {
        val line = lines[i].trim()
        val (key, neighbours) = line.split(":")
        if (neighbours.isNotEmpty()) {
            graph[key] = neighbours.trim().split(" ")
        }
    }

    val start = lines[N + 1].trim()

    fun invertMap(map: Map<String, List<String>>): Map<String, List<String>> {
        val invertedMap = mutableMapOf<String, MutableList<String>>()
        for ((key, neighbours) in map) {
            for (neighbour in neighbours) {
                if (!invertedMap.containsKey(neighbour)) {
                    invertedMap[neighbour] = mutableListOf(key)
                } else {
                    invertedMap[neighbour]?.add(key)
                }
            }
        }
        return invertedMap
    }


    // Step 1 is to invert the map
    val invertedGraph = invertMap(graph)

    // Step 2 is to do a topological sort (reference: Neetcode 210)
    fun toposort(graph: Map<String, List<String>>, start: String): List<String> {
        val output = mutableListOf<String>()
        val visited = mutableSetOf<String>()

        tailrec fun dfs(node: String) {
            if (node in visited) {
                return
            }
            for (neighbour in graph[node] ?: emptyList()) {
                dfs(neighbour)
            }

            visited.add(node)
            output.add(node)
        }

        dfs(start)
        return output.reversed()
    }

    for (i in toposort(invertedGraph, start)) {
        println(i)
    }
}

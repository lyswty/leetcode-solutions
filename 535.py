class Codec:
    
    def __init__(self):
        self.mp = {}
        self.cnt = 0

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        self.mp[self.cnt] = longUrl
        shortUrl = "http://"+str(self.cnt)
        self.cnt += 1
        return shortUrl

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.mp[int(shortUrl[7::])]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
